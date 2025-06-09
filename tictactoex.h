// AiLinh
// tictactoex.h
// Purpose:

#include <iostream>

using namespace std;

#ifndef TICTACTOE_H
#define TICTACTOE_H

class Tictactoe{

private:

  static const char CROSS = 'X';
  static const char CIRCLE ='O';
  static const char SPACE =' ';
  static const char DIVIDER = '|';
  static const string U_DIVIDER;
  
  char** board;
  int size = 0;

public:

  Tictactoe();
  // Default Constructor
  
  // Tictactoe(int s);
  // Constructor

  Tictactoe& operator=( const Tictactoe& rhs);
  // overloaded assignment operator

  Tictactoe(const Tictactoe &t);
  // copy constructor
  
  ~Tictactoe();
  // Destructor

  void setSize (int s);
  // set the size for the game board
  
  void displayBoard();
  // display the game board
  
  bool checkWin();
  // check for the winner
  // return true if there is a winner
  // else return false

  bool checkDraw();
  // check for draw
  // return true if the board is filled but no winner
  // else return false
  
  bool takeTurn( int row, int col, bool turnX);
  // take turn
  // return false when the chosen row and col is not empty
  // otherwise fill the slot with the appropriate sign and return true

  void restart();
  // set up board for new game

};

#endif // TICTACTOE_H
