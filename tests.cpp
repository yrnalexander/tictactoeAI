#include<gtest/gtest.h>
#include"include/board.h"
#include<vector>
#include<iostream>

//0 1 2     Tie/ X wins/ O wins
// -1 error

int playGame(std::vector<int> a)
{
    if(a.size() < 0 || a.size() > 9)
    {
        //std::cout<<"invalid game";
        return -1;
    }
    Board game;
    int i =0;
    while(game.check_win() == -1)
    {
        if(game.make_move(a[i]) == -1)
        {
            //std::cout<<"Illegal move\n";
            return -1;
        }
        i++;
    }
    //game.announce();
    return game.get_win();
}

/*
  suit1 are 4 basic tests
  suit2 - x win tests
  suit3 - o win tests
  suit4 - ties tests
  suit5 - invalid games/unfininshed games tests

  suit 2,3,4,5 - TO DO
*/

TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

//expected: x wins
TEST(suit1, test1)
{
  std::vector<int> a = {1,5,6,7,3,9,2};
  const int result = playGame(a);
  ASSERT_EQ(result,1);
}
//expected: o wins
TEST(suit1, test2)
{
  std::vector<int> a = {2,3,8,5,6,7};
  const int result = playGame(a);
  ASSERT_EQ(result,2);
}
//expected: tie
TEST(suit1, test3)
{
  std::vector<int> a = {1,5,9,6,4,7,3,2,8};
  const int result = playGame(a);
  ASSERT_EQ(result,0);
}
//expected: not finished
TEST(suit1, test4)
{
  std::vector<int> a = {1,7};
  const int result = playGame(a);
  ASSERT_EQ(result,-1);
}

//suit 2
TEST(suit2, test1)
{
  std::vector<int> a = {5,3,9,1,2,4,8};
  const int result = playGame(a);
  ASSERT_EQ(result,1);
}
TEST(suit2, test2)
{
  std::vector<int> a = {9,1,3,6,7,5,8};
  const int result = playGame(a);
  ASSERT_EQ(result,1);
}
TEST(suit2, test3)
{
  std::vector<int> a = {4,7,5,8,6};
  const int result = playGame(a);
  ASSERT_EQ(result,1);
}
//suit 3
TEST(suit3, test1)
{
  std::vector<int> a = {1,5,4,7,2,3};
  const int result = playGame(a);
  ASSERT_EQ(result,2);
}
TEST(suit3, test2)
{
  std::vector<int> a = {6,1,9,3,5,2};
  const int result = playGame(a);
  ASSERT_EQ(result,2);
}
TEST(suit3, test3)
{
  std::vector<int> a = {4,5,6,8,9,2};
  const int result = playGame(a);
  ASSERT_EQ(result,2);
}
//suit 4
TEST(suit4, test1)
{
  std::vector<int> a = {5,6,4,1,3,7,8,2,9};
  const int result = playGame(a);
  ASSERT_EQ(result,0);
}
TEST(suit4, test2)
{
  std::vector<int> a = {8,5,3,6,4,1,9,7,2};
  const int result = playGame(a);
  ASSERT_EQ(result,0);
}
TEST(suit4, test3)
{
  std::vector<int> a = {2,7,3,1,4,6,5,8,9};
  const int result = playGame(a);
  ASSERT_EQ(result,0);
}
//suit 5
TEST(suit5, test1)
{
  std::vector<int> a = {2,3,1,6,7};
  const int result = playGame(a);
  ASSERT_EQ(result,-1);
}
TEST(suit5, test2)
{
  std::vector<int> a = {7,1,4,2,3,5};
  const int result = playGame(a);
  ASSERT_EQ(result,-1);
}
TEST(suit5, test3)
{
  std::vector<int> a = {1,9,3,7};
  const int result = playGame(a);
  ASSERT_EQ(result,-1);
}

//suit 6 - testing remove_move
TEST(suit6, test1)
{
  Board game;
  game.make_move(2);
  game.make_move(3);
  game.make_move(9);

  int turns = game.get_turns();
  ASSERT_EQ(turns,3);

  game.remove_move(3);
  game.remove_move(5);

  turns = game.get_turns();
  ASSERT_EQ(turns,2);

  ASSERT_EQ(' ', game.get_square(0,2));
}

//suit 7 - not used

//suit 8 - testing next_moves function
TEST(suit8, test1)
{
  Board game;
  game.make_move(5);
  game.make_move(1);
  game.make_move(9);
  game.make_move(7);

  std::vector<int> my_vec = game.next_moves();
  ASSERT_EQ(my_vec.size(),5);
  ASSERT_EQ(my_vec[0],2);
  ASSERT_EQ(my_vec[1],3);
  ASSERT_EQ(my_vec[2],4);
  ASSERT_EQ(my_vec[3],6);
  ASSERT_EQ(my_vec[4],8);

  game.remove_move(7);
  game.remove_move(1);

  my_vec = game.next_moves();
  
  ASSERT_EQ(my_vec.size(),7);
  ASSERT_EQ(my_vec[0],1);
  ASSERT_EQ(my_vec[1],2);
  ASSERT_EQ(my_vec[2],3);
  ASSERT_EQ(my_vec[3],4);
  ASSERT_EQ(my_vec[4],6);
  ASSERT_EQ(my_vec[5],7);
  ASSERT_EQ(my_vec[6],8);

}


