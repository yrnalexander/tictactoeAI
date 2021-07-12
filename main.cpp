
#include "include/board.h"
#include <vector>
#include <random>
#include <limits>



int max_value(Board);
int min_value(Board);


//returns the value of a decision
int max_value(Board state)
{
    if(state.check_win() == 0)
        return 0;
    if(state.check_win() == 1)
        return 10;
    if(state.check_win() == 2)
        return -10;

    int v = -1000;
    std::vector<int> moves = state.next_moves();
    for(int i=0; i<moves.size(); i++)
    {
        state.make_move(moves[i]);
        int temp = min_value(state);
        if(temp > v)
        {
            v = temp;
        }
        state.remove_move(moves[i]);
    }
    return v;
}

//returns the value of a decision
int min_value(Board state)
{
    if(state.check_win() == 0)
        return 0;
    if(state.check_win() == 1)
        return 10;
    if(state.check_win() == 2)
        return -10;
    int v = 1000;
    std::vector<int> moves = state.next_moves();
    for(int i = 0; i<moves.size(); i++)
    {
        state.make_move(moves[i]);
        int temp = max_value(state);
        if(temp < v)
        {
            v = temp;
        }        
        state.remove_move(moves[i]);
    }
    return v;
}

//returns the actual best decision for X
int minimax_x(Board state)
{
    int v = -1000;
    int decision = -1;
    std::vector<int> moves = state.next_moves();
    for(int i=0; i<moves.size(); i++)
    {
        state.make_move(moves[i]);
        int temp = min_value(state);
        if(temp > v)
        {
            v = temp;
            decision = moves[i];
        }
        state.remove_move(moves[i]);
    }
    return decision;
}

//returns the actual best decision for X
int minimax_o(Board state)
{
    int v = 1000;
    int decision = -1;
    std::vector<int> moves = state.next_moves();
    for(int i=0; i<moves.size(); i++)
    {
        state.make_move(moves[i]);
        int temp = max_value(state);
        if(temp < v)
        {
            v = temp;
            decision = moves[i];
        }
        state.remove_move(moves[i]);
    }
    return decision;
}

//play a game of tictactoe
void play_game()
{
    Board game;
    while(game.check_win() == -1)
    {
        game.print_board();
        //Next line determines the player
        if(game.get_turns()%2 == 0)
        {
            int n = minimax_x(game);
            game.make_move(n);
        }
        else
        {
            int n;
            std::cout<<"Choose a move 1-9: ";
            std::cin>>n;
            game.make_move(n);
        }
        std::cout<<'\n';
    }
    game.print_board();
    if(game.get_win() == 0)
    {
        std::cout<<"Tie"<<'\n';
    }
    else if(game.get_win() == 1)
    {
        std::cout<<"X wins"<<'\n';
    }
    else if(game.get_win() == 2)
    {
        std::cout<<"O wins"<<'\n';
    }
    else
    {
        std::cout<<"ERROR"<<'\n';
    }
}


int main()
{
    play_game();
    return 0;
}