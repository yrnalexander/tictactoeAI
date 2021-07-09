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
/*
Board::Board(Board& copy)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            board[i][j] = copy.board[i][j];
        }
    }
    turns = copy.turns;
    win = copy.win;
}
*/
char Board::get_square(int x, int y)
{
    if(x >=0 && x<3 && y>=0 && y<3)
    {
        return board[x][y];
    }
    else
    {
        return -1;
    }
}
int Board::index_to_int(int x, int y)
{
    if(x > 2 || x < 0 || y > 2 || y < 0)
    {
        std::cout<<"Fatal";
        exit(1);
    }
    if(x == 0 && y == 0)
    {
        return 1;
    }
    else if(x == 0 && y == 1)
    {
        return 2;
    }
    else if(x == 0 && y == 2)
    {
        return 3;
    }
    else if(x == 1 && y == 0)
    {
        return 4;
    }
    else if(x == 1 && y == 1)
    {
        return 5;
    }
    else if(x == 1 && y == 2)
    {
        return 6;
    }
    else if(x == 2 && y == 0)
    {
        return 7;
    }
    else if(x == 2 && y == 1)
    {
        return 8;
    }
    else if(x == 2 && y == 2)
    {
        return 9;
    }
}
std::vector<int> Board::hasMove()
{
    std::vector<int> out;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j] == ' ')
            {
                int result = index_to_int(i,j);
                out.push_back(result);

            }
        }
    }
    return out;
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

int Board::empty(int x, int y)
{
    if(x < 0 || x > 2 || y < 0 || y > 2)
    {
        return -1;
    }
    if(board[x][y] == ' ')
    {
        return -1;
    }
    else
    {
        board[x][y] = ' ';
        turns--;
        return 0;
    }
}

void Board::set_ai(int a)
{
    ai_decision = a;
}

int Board::get_ai()
{
    
    return ai_decision;
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

int Board::removeMove(int n)
{
    switch(n)
    {
        case 1:
            return empty(0,0);
        case 2:
            return empty(0,1);
        case 3:
            return empty(0,2);
        case 4:
            return empty(1,0);
        case 5:
            return empty(1,1);
        case 6:
            return empty(1,2);
        case 7:
            return empty(2,0);
        case 8:
            return empty(2,1);
        case 9:
            return empty(2,2);
        default:
            return -1;
    }
    return 0;
}

int Board::checkWinHorizontal()
{   
    
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == 'X')
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
    else if(turns == 9)
    {
        win = 0;
        return 0;
    }
    return -1;
}

int Board::checkWinVetrical()
{
    
    if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] == 'X')
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
    else if(turns == 9)
    {
        win = 0;
        return 0;
    }
    return -1;
}

int Board::checkWinDiagonal()
{
    
    if( board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'X')
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
    else if(turns == 9)
    {
        win = 0;
        return 0;
    }
    return -1;
}

int Board::check_win()
{
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == 'X')
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
    else if(turns == 9)
    {
        win = 0;
        return 0;
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
    std::cout<<"\n";
}