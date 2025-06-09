// AiLinh
// tictactoex.cpp
// Implementation of tictactoex.h

#include "tictactoex.h"
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

const string Tictactoe::U_DIVIDER ="----";

// Contructor
Tictactoe::Tictactoe(){
  size = 3;
  board = nullptr;
  
}

// overloaded assigment operator
Tictactoe&  Tictactoe:: operator= (const Tictactoe& rhs){
  
  if ( this != &rhs ){
    for ( int r = 0; r < size; r++){
      for ( int c = 0; c < size; c++){
        board[r][c] = rhs.board[r][c];
      }
    }
  }
  
  return *this;
  
}


// copy constructor
Tictactoe:: Tictactoe (const Tictactoe& t){
  
  board = new char*[size];

  for ( int i = 0; i < size; i++){
    board[i] = new char[size];
  }
  
  for ( int i = 0; i < size; i++){
    for ( int j = 0; j < size; j++){
      board[i][j] = t.board[i][j];
    }
  }
   
}

// destructor
Tictactoe::~Tictactoe(){
  for ( int i = 0; i < size; i++){
    delete[] board[i];  
  }
  
  delete[] board;
  
}


void Tictactoe::setSize( int s){

  if ( s % 2 == 0){
    size = s+1;
  }
  else {
    size = s;
  }

  if (board != nullptr) {
    for (int i = 0; i < size; i++) {
      delete[] board[i];
    }
    delete[] board;
  }

  
  board = new char*[size]; 
  for ( int i = 0; i < size; i++){
    board[i] = new char[size];
  }
  
  for ( int i = 0; i < size; i++){
    for ( int j = 0; j < size; j++){
      board[i][j] = SPACE;
    }
  }
  
}


// print board
void Tictactoe::displayBoard(){

  cout << endl << endl;
  cout << SPACE << SPACE;
  // label the column
  for ( int i = 0; i < size; i++ ){
    cout << SPACE <<  i << SPACE << SPACE;
  }

  cout << endl;

  // label row and print board
  for ( int i = 0; i < size; i++ ) {
    cout << SPACE << i << SPACE;
    for ( int j = 0; j < size; j++ ){
      cout << board[i][j] << SPACE << SPACE << DIVIDER;
    }
    
    cout << endl << SPACE << SPACE << SPACE;
    for ( int z = 0; z < size; z++){
      cout << U_DIVIDER;
    }
    cout << endl;
  }
  
  
}

// check for winner
// return true if there is a winner
// otherwise return false
bool Tictactoe:: checkWin()
{
  bool diagLR = true;
  bool diagRL = true;  
  bool winRow = false;
  bool winCol = false;
  
  for ( int row = 0; row < size; row++){
    bool rowWin = true;
    for ( int j = 1; j < size; j++ ){
      if ( board[row][j] == SPACE || board[row][j] != board[row][j-1] ){
        rowWin = false;
      }
    }
    
    
    if (rowWin){
      winRow = true;
    }
  }
  
  
  // check col
  
  
  for(int col = 0; col < size; col++){
    bool colWin = true;
    for ( int i = 1; i < size; i++ ){
      if ( board[i][col] == SPACE || board[i][col] != board[i-1][col] ){
        colWin = false;
      }
    }
  
  
    if ( colWin ){
      winCol = true;
    }
  }
  
  // check diag Left to right
  for ( int i = 1 ; i < size ; i++){
    if ( board[i][i] == SPACE || board[i][i] != board[i-1][i-1]){
      diagLR = false;
    }
  }
  

  
  // check diag Right to left
  for ( int i = 1; i < size ; i++ ){
    if ( board[i][size-1-i] == SPACE || board[i][size-1-i] != board[i-1][size-i]){
      diagRL = false;
    }
  }

  if (winRow|| winCol|| diagLR || diagRL){
    return true;
  }
  
  return false;
}


// check the chosen row and col
// return true and assign the appropriate sign if spot is available
// otherwise return false
bool Tictactoe:: takeTurn (int row, int col, bool turnX){
  if ( row ==-1 || col ==-1){
    return false;
  }

  
  if ( board[row][col] == SPACE ){
    if ( turnX){
      board[row][col] = CROSS;
    }
    else{
      board[row][col] = CIRCLE;
    }
    return true;
  }
  else{
    // the chosen spot is not empty
    return false;
  }
}

// check if the game is draw
// return true if it is a draw game
// otherwise return false
bool Tictactoe:: checkDraw(){
  
  bool filled = true;
  // flag to check whether the whole board is filled or not
  
  
  for ( int i = 0; i < size; i++){
    for ( int j = 0; j < size; j++){
      if ( board[i][j] == SPACE){
        filled = false;
      }
    }
  }

  // if the board is filled but there is no winner
  // return true
  // otherwise return false
  if ( filled && !checkWin()){
    return true;
  }
  else {
    return false;
  }
  
}


// reset the board for new game
void Tictactoe:: restart(){
  for ( int i = 0; i < size; i++){
    for ( int j = 0; j < size; j++){
      board[i][j] = SPACE;
    }
  }
}


