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

    //get/set/print
    char get_square(int,int);
    int get_turns();
    int get_win();

    void print_board();

    //utility
    int make_move(int);
    int remove_move(int);
    std::vector<int> next_moves();
    int check_win();


};
