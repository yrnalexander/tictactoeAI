#include "include/board.h"

int index_hint(int x, int y)
{
    if(x == 0 && y == 0)
        return 1;
    if(x == 0 && y == 1)
        return 2;
    if(x == 0 && y == 2)
        return 3;
    if(x == 1 && y == 0)
        return 4;
    if(x == 1 && y == 1)
        return 5;
    if(x == 1 && y == 2)
        return 6;
    if(x == 2 && y == 0)
        return 7;
    if(x == 2 && y == 1)
        return 8;
    if(x == 2 && y == 2)
        return 9;
    return -1;
}

Board::Board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    win = -1;
    turns = 0;
}
//make a move on the board - 1,2,3...9
//return 0 on success -1 on failure
int Board::make_move(int n)
{
    if(n == 1)
    {
        if(board[0][0] == ' ')
        {
            if(turns%2 == 0)
            {
                board[0][0] = 'X';
                turns++;
                return 0;
            }
            else
            {
                board[0][0] = 'O';
                turns++;
                return 0;
            }
        }
        else
        {
            std::cout<<"Invalid Move";
            return -1;
        }
    }
    else if(n == 2)
    {
        if(board[0][1] == ' ')
        {
            if(turns%2 == 0)
            {
                board[0][1] = 'X';
                turns++;
                return 0;
            }
            else
            {
                board[0][1] = 'O';
                turns++;
                return 0;
            }
        }
        else
        {
            std::cout<<"Invalid Move";
            return -1;
        }
    }
    else if(n == 3)
    {
        if(board[0][2] == ' ')
        {
            if(turns%2 == 0)
            {
                board[0][2] = 'X';
                turns++;
                return 0;
            }
            else
            {
                board[0][2] = 'O';
                turns++;
                return 0;
            }
        }
        else
        {
            std::cout<<"Invalid Move";
            return -1;
        }
    }
    else if(n == 4)
    {
        if(board[1][0] == ' ')
        {
            if(turns%2 == 0)
            {
                board[1][0] = 'X';
                turns++;
                return 0;
            }
            else
            {
                board[1][0] = 'O';
                turns++;
                return 0;
            }
        }
        else
        {
            std::cout<<"Invalid Move";
            return -1;
        }
    }
    else if(n == 5)
    {
        if(board[1][1] == ' ')
        {
            if(turns%2 == 0)
            {
                board[1][1] = 'X';
                turns++;
                return 0;
            }
            else
            {
                board[1][1] = 'O';
                turns++;
                return 0;
            }
        }
        else
        {
            std::cout<<"Invalid Move";
            return -1;
        }
    }
    else if(n == 6)
    {
        if(board[1][2] == ' ')
        {
            if(turns%2 == 0)
            {
                board[1][2] = 'X';
                turns++;
                return 0;
            }
            else
            {
                board[1][2] = 'O';
                turns++;
                return 0;
            }
        }
        else
        {
            std::cout<<"Invalid Move";
            return -1;
        }
    }
    else if(n == 7)
    {
        if(board[2][0] == ' ')
        {
            if(turns%2 == 0)
            {
                board[2][0] = 'X';
                turns++;
                return 0;
            }
            else
            {
                board[2][0] = 'O';
                turns++;
                return 0;
            }
        }
        else
        {
            std::cout<<"Invalid Move";
            return -1;
        }
    }
    else if(n == 8)
    {
        if(board[2][1] == ' ')
        {
            if(turns%2 == 0)
            {
                board[2][1] = 'X';
                turns++;
                return 0;
            }
            else
            {
                board[2][1] = 'O';
                turns++;
                return 0;
            }
        }
        else
        {
            std::cout<<"Invalid Move";
            return -1;
        }
    }
    else if(n == 9)
    {
        if(board[2][2] == ' ')
        {
            if(turns%2 == 0)
            {
                board[2][2] = 'X';
                turns++;
                return 0;
            }
            else
            {
                board[2][2] = 'O';
                turns++;
                return 0;
            }
        }
        else
        {
            std::cout<<"Invalid Move";
            return -1;
        }
    }
    std::cout<<"Invalid move";
    return -1;
}
//remove a move
//return 0 on success -1 on failure
int Board::remove_move(int n)
{
    if(n == 1)
    {
        if(board[0][0] != ' ')
        {
            board[0][0] = ' ';
            turns --;
            return 0;
        }
        else
        {
            std::cout<<"Invalid remove";
            return -1;
        }
    }
    else if(n == 2)
    {
        if(board[0][1] != ' ')
        {
            board[0][1] = ' ';
            turns --;
            return 0;
        }
        else
        {
            std::cout<<"Invalid remove";
            return -1;
        }
    }
    else if(n == 3)
    {
        if(board[0][2] != ' ')
        {
            board[0][2] = ' ';
            turns --;
            return 0;
        }
        else
        {
            std::cout<<"Invalid remove";
            return -1;
        }
    }
    else if(n == 4)
    {
        if(board[1][0] != ' ')
        {
            board[1][0] = ' ';
            turns --;
            return 0;
        }
        else
        {
            std::cout<<"Invalid remove";
            return -1;
        }
    }
    else if(n == 5)
    {
        if(board[1][1] != ' ')
        {
            board[1][1] = ' ';
            turns --;
            return 0;
        }
        else
        {
            std::cout<<"Invalid remove";
            return -1;
        }
    }
    else if(n == 6)
    {
        if(board[1][2] != ' ')
        {
            board[1][2] = ' ';
            turns --;
            return 0;
        }
        else
        {
            std::cout<<"Invalid remove";
            return -1;
        }
    }
    else if(n == 7)
    {
        if(board[2][0] != ' ')
        {
            board[2][0] = ' ';
            turns --;
            return 0;
        }
        else
        {
            std::cout<<"Invalid remove";
            return -1;
        }
    }
    else if(n == 8)
    {
        if(board[2][1] != ' ')
        {
            board[2][1] = ' ';
            turns --;
            return 0;
        }
        else
        {
            std::cout<<"Invalid remove";
            return -1;
        }
    }
    else if(n == 9)
    {
        if(board[2][2] != ' ')
        {
            board[2][2] = ' ';
            turns --;
            return 0;
        }
        else
        {
            std::cout<<"Invalid remove";
            return -1;
        }
    }
    std::cout<<"Invalid remove";
    return -1;

}
// 0 - Tie / 1 - X / 2 - O / -1 - Still playing
int Board::check_win()
{
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == 'X')
    {
        win = 1;
        return 1;
    }
    else if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == 'O')
    {
        win = 2;
        return 2;
    }
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] == 'X')
    {
        win = 1;
        return 1;
    }
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] == 'O')
    {
        win = 2;
        return 2;
    }
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] == 'X')
    {
        win = 1;
        return 1;
    }
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] == 'O')
    {
        win = 2;
        return 2;
    }
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] == 'X')
    {
        win = 1;
        return 1;
    }
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] == 'O')
    {
        win = 2;
        return 2;
    }
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] == 'X')
    {
        win = 1;
        return 1;
    }
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] == 'O')
    {
        win = 2;
        return 2;
    }
    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] == 'X')
    {
        win = 1;
        return 1;
    }
    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] == 'O')
    {
        win = 2;
        return 2;
    }
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'X')
    {
        win = 1;
        return 1;
    }
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'O')
    {
        win = 2;
        return 2;
    }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'X')
    {
        win = 1;
        return 1;
    }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'O')
    {
        win = 2;
        return 2;
    }
    else if (turns == 9)
    {
        win = 0;
        return 0;
    }
    return -1;
}
// return a vector contating the possible next moves of a state
std::vector<int> Board::next_moves()
{
    std::vector<int> output;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j] == ' ')
            {
                int move = index_hint(i,j);
                output.push_back(move);
            }
        }
    }
    return output;
}

//getters
char Board::get_square(int x, int y)
{
    if(x < 0 || x > 2 || y < 0 || y > 2)
    {
        return -1;
    }
    else
    {
        return board[x][y];
    }
}
int Board::get_win()
{
    return win;
}
int Board::get_turns()
{
    return turns;
}

//setters
void Board::print_board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "|";
            std::cout << board[i][j];
        }
        std::cout << "|";
        std::cout << "\n";
    }
    std::cout << "\n";
}