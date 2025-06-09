// AiLinh
// p2x.cpp
// Allow 2 players to play TicTacToe in a chosen size of board

#include <iostream>
#include <cctype>
#include "tictactoex.h"

using namespace std;

const char YES ='y';
const int CLEAR = 25;
const int MIN = 0;
const int MIN_SIZE = 3;
const int MAX_SIZE = 9;

void welcome();
// print welcome message

void goodbye();
// print goodbye message

void clrScr();
// clear screen

int main(){
  
  Tictactoe game;
  char choice =' ';
  bool turnX = true;
  int row = -1;
  int col = -1;
  int winX = 0;
  int winO = 0;
  int size = 0;
  
  clrScr();
  welcome();
  cout << "Play ? (y/n) : ";
  cin >> choice;
  cout << endl;
  
  if (choice == YES || choice == toupper(YES)){
    
    cout << "What size of board (odd number)? ("
         << MIN_SIZE <<" - " << MAX_SIZE <<"): ";
    cin >> size;
    game.setSize(size);
    if ( size % 2 == 0){
      size++;
    }
    
  }
  
  while ( choice == YES || choice == toupper(YES)){
    game.restart();
    turnX= true;
    
    while ( !game.checkWin() && !game.checkDraw() ){
      if ( turnX) {
        cout << endl << endl << "Player 1 [X]: " << endl << endl;
        game.displayBoard();
        cout << endl << endl;
        
        while ( !game.takeTurn(row,col,turnX) ) {
          row = -1;
          col = -1;
          while ( row < MIN || row > size-1 ){
            
            cout << "Enter row ("  << MIN <<"-" << size-1 <<"): ";
            cin >> row;
            cin.ignore();
          }
          
          while ( col < MIN || col > size-1 ){
            
            cout << "Enter column (" << MIN <<"-" << size-1 <<"): ";
            cin >> col;
            cin.ignore();
          }
        }
        
        game.displayBoard();
        turnX = false;
        row = -1;
        col = -1;
        
      }
      else {
        cout << endl << endl << "Player 2 [O]: " << endl << endl;
        game.displayBoard();
        cout << endl << endl;
        while ( !game.takeTurn(row,col,turnX) ) {
          row = -1;
          col = -1;
          while ( row < MIN || row > size-1 ){
            
            cout << "Enter row ("  << MIN <<"-" << size-1 <<"): ";
            cin >> row;
          }
          
          while ( col < MIN || col > size-1 ){
            
            cout << "Enter column (" << MIN <<"-" << size-1 <<"): ";
            cin >> col;
          }
        }
        
        game.displayBoard();
        turnX = true;
        row = -1;
        col = -1;
        
        
      }
    }
    cout << endl;
    if ( game.checkWin()){
      if ( turnX){
        cout << "Player 2 [O] win!" << endl << endl;
        winO++;
      }
      else {
        cout << "Player 1 [X] win!" << endl << endl;
        winX++;
      }
    }
    else{
      cout << "DRAW GAME!" << endl << endl;
    }
    
    cout << endl << "Player 1 [X]: " << winX << endl;
    cout << "Player 2 [O]: " << winO;
    cout << endl << endl << "Again? (y/n): " ;
    cin >> choice;
  }
  
  goodbye();
  
  return 0;
}

void welcome(){
  
  cout << endl << endl;
  cout << "Welcome to TicTacToe!" << endl << endl;
  cout << " The game is for two players." << endl
       << " One player places the X pieces"
       << " and the other player places the O pieces. "
       << endl << " When one player covers an entire row,"
       << " column or diagonal," << endl <<" that player wins the game."
       << endl << endl;
}

void goodbye(){
  
  cout << endl << endl;
  cout << "Thank you for playing!" << endl << endl;

}

void clrScr(){

  for ( int i = 0; i < CLEAR; i++){
    cout << endl;
  }
  
}
