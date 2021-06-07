#include"include/board.h"

Board::Board()
{
    
    for(int i = 0; i<3 ;i++)
    {
        for(int j=0; j<3; j++)
        {
            board[i][j] = ' ';
        }
    }
    win = -1;
    turns = 0;
}
int Board::place(int x, int y)
{
    if(board[x][y] == 'X' || board[x][y] == 'O')
    {
        return -1;
    }
    else
    {
        if(turns%2 == 0)
        {
            board[x][y] = 'X';
        }
        else
        {
            board[x][y] = 'O';
        }
        turns++;
        return 0;
    }

}

int Board::makeMove(int n)
{
    switch(n)
    {
        case 1:
            return place(0,0);
        case 2:
            return place(0,1);
        case 3:
            return place(0,2);
        case 4:
            return place(1,0);
        case 5:
            return place(1,1);
        case 6:
            return place(1,2);
        case 7:
            return place(2,0);
        case 8:
            return place(2,1);
        case 9:
            return place(2,2);
        default:
            return -1;
    }
    return 0;
}

int Board::checkWinHorizontal()
{   
    if(turns == 9)
    {
        win = 0;
        return 0;
    }
    else if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == 'X')
    {
        win = 1;
        return 1;
    }
    else if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == 'O')
    {
        win = 2;
        return 2;
    }
    else if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] == 'X')
    {
        win = 1;
        return 1;
    }
    else if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] == 'O')
    {
        win = 2;
        return 2;
    }
    else if(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] == 'X')
    {
        win = 1;
        return 1;
    }
    else if(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] == 'O')
    {
        win = 2;
        return 2;
    }
    return -1;
}

int Board::checkWinVetrical()
{
    if(turns == 9)
    {
        win = 0;
        return 0;
    }
    else if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] == 'X')
    {
        win = 1;
        return 1;
    }
    else if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] == 'O')
    {
        win = 2;
        return 2;
    }
    else if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] == 'X')
    {
        win = 1;
        return 1;
    }
    else if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] == 'O')
    {
        win = 2;
        return 2;
    }
    else if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] == 'X')
    {
        win = 1;
        return 1;
    }
    else if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] == 'O')
    {
        win = 2;
        return 2;
    }
    return -1;
}

int Board::checkWinDiagonal()
{
    if(turns == 9)
    {
        win = 0;
        return 0;
    }
    else if( board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'X')
    {
        win = 1;
        return 1;
    }
    else if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'O')
    {
        win = 2;
        return 2;
    }
    else if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'X')
    {
        win = 1;
        return 1;
    }
    else if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'O')
    {
        win = 2;
        return 2;
    }
    return -1;
}

void Board::announce()
{
    if(win == 0)
    {
        std::cout<<"TIE\n";
    }
    else if(win == 1)
    {
        std::cout<<"X wins\n";
    }
    else if(win == 2)
    {
        std::cout<<"O wins\n";
    }
    else if(win == -1)
    {
        std::cout<<"game not finished\n";
    }
    else
    {
        std::cout<<"ERROR\n";
    }
    
    
}
int Board::getWin()
{
    return win;
}

void Board::printBoard()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            std::cout<<"|";
            std::cout<<board[i][j];
        }
        std::cout<<"|";
        std::cout<<"\n";
        
    }
    std::cout<<"\n"<<"\n"<<"\n";
}