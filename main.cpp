
#include "include/board.h"
#include <vector>
//0 1 2     Tie/ X wins/ O wins
// -1 error
int playGame(std::vector<int> a)
{
    if(a.size() < 5 || a.size() > 9)
    {
        std::cout<<"invalid game";
        return -1;
    }
    Board game;
    int i =0;
    while(game.checkWinDiagonal() == -1 && game.checkWinVetrical() == -1 && game.checkWinHorizontal() == -1)
    {
        if(game.makeMove(a[i]) == -1)
        {
            std::cout<<"Illegal move\n";
            return -1;
        }
        i++;
    }
    game.announce();
    return game.getWin();
}
int main()
{

    std::vector<int> game1 = {2,3,4,1,5,7,8};
    std::cout<<playGame(game1);
    return 0;  
}