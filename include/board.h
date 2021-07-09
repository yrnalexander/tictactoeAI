#include<iostream>
#include<vector>
#include<cstring>
struct coordinate
{
    int x;
    int y;
};
class Board
{
    char board[3][3];
    int turns;
    int win; // -1 0 1 2    Still Playing/ Tie/ X wins/ O wins
    int ai_decision;
    
    public:

    Board();
    //Board(Board& copy);
    void printBoard();
    int index_to_int(int, int);
    std::vector<int> hasMove(); // return index of avail move or -1 on full board
    int place(int x, int y);
    int empty(int x, int y);
    void set_ai(int a);
    int get_ai();
    char get_square(int x, int y);
    int makeMove(int n); // -1 on failure 0 on success
    int removeMove(int n);
    int checkWinHorizontal();
    int checkWinVetrical();
    int checkWinDiagonal();

    int check_win();
    void announce();
    int getWin();
};
