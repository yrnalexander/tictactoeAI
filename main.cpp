
#include "include/board.h"
#include <vector>
#include <random>
#include <limits>

/*TODO

 Try implementig the algo wiht pointers

*/

//0 1 2     Tie/ X wins/ O wins
// -1 error

//Plug a vector of moves and see how the game ends
int replayGame(std::vector<int> a)
{
    if (a.size() < 5 || a.size() > 9)
    {
        std::cout << "invalid game";
        return -1;
    }
    Board game;
    int i = 0;
    while (game.checkWinDiagonal() == -1 && game.checkWinVetrical() == -1 && game.checkWinHorizontal() == -1)
    {
        if (game.makeMove(a[i]) == -1)
        {
            std::cout << "Illegal move\n";
            return -1;
        }
        i++;
    }
    game.announce();
    return game.getWin();
}

//MiniMax algo
//Utility X wins  1
//        O wins -1
//        Tie     0
int max_val(Board*);
int min_val(Board*);

int max_val(Board* state)
{
    //sort utility
    if (state->check_win() != -1)
    {
        if (state->getWin() == 0)
        {
            return 0;
        }
        else if (state->getWin() == 1)
        {
            return 1;
        }
        else if (state->getWin() == 2)
        {
            return -1;
        }
    }
    std::vector<int> moves = state->hasMove();
    state->makeMove(moves[0]);
    int v = min_val(state);
    state->set_ai(0);
    state->removeMove(moves[0]);
    for(int i=1; i<moves.size(); i++)
    {
        state->makeMove(moves[i]);
        int temp = min_val(state);
        state->removeMove(moves[i]);
        if (temp > v)
        {
            v = temp;
            state->set_ai(i);
        }
    }
    return v;

}

int min_val(Board *state)
{
    int v = std::numeric_limits<int>::max();
    std::vector<int> moves = state->hasMove();
    for(int i=0; i<moves.size(); i++)
    {   
        state->makeMove(moves[i]);
        int temp = max_val(state);
        state->removeMove(moves[i]);
        if (temp < v)
        {
            v = temp;
            state->set_ai(i);
        }
    }
    return v;

}

int minimax_decision(Board* state)
{
    int v = max_val(state);
    return state->get_ai();
}

//Play a 2-player game
int playGame()
{
    Board game;
    int i = 0;
    while (game.check_win() == -1)
    {
        std::vector<int> my_vec = game.hasMove();
        for (int i = 0; i < my_vec.size(); i++)
        {
            std::cout << "I can make move:" << my_vec[i] << '\n';
        }
        if(i%2 == 0)
        {
            int decision = minimax_decision(&game);
            std::cout<<"best move is: "<<decision<<'\n';
        }
        int num;
        game.printBoard();
        std::cout << "Choose a move 1-9:";
        std::cin >> num;
        if (game.makeMove(num) == -1)
        {
            std::cout << "Illegal move\n";
            continue;
        }
        i++;
    }
    game.printBoard();
    game.announce();
    return game.getWin();
}

int playComputer()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 9);
    Board game;
    int i = 0;
    while (game.checkWinDiagonal() == -1 && game.checkWinVetrical() == -1 && game.checkWinHorizontal() == -1)
    {
        if (i % 2 == 0)
        {
            int num;
            game.printBoard();
            std::cout << "Choose a move 1-9:";
            std::cin >> num;
            if (game.makeMove(num) == -1)
            {
                std::cout << "Illegal move\n";
                continue;
            }
            i++;
        }
        else
        {
            game.printBoard();
            //put in AI
            int num = distrib(gen);
            while (game.makeMove(num) == -1)
            {
                num = distrib(gen);
            }
            i++;
        }
    }
    game.printBoard();
    game.announce();
    return game.getWin();
}

int main()
{

    std::vector<int> game1 = {1, 2, 3, 4, 5, 6};
    //std::cout<<replayGame(game1);
    playGame();
    //playComputer();
    return 0;
}