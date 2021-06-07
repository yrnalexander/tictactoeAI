#include<iostream>
#include<vector>
#include<cstring>

class Board
{
    char board[3][3];
    int turns;
    int win; // -1 0 1 2    Still Playing/ Tie/ X wins/ O wins
    
    public:

    Board();
    void printBoard();
    int place(int x, int y);
    int makeMove(int n); // -1 on failure 0 on success
    int checkWinHorizontal();
    int checkWinVetrical();
    int checkWinDiagonal();
    void announce();
    int getWin();
};