#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

string winner = "";
void display_board(string []);
void playGame(string [], bool &, string);
void handleTurn(string [], string);
void checkIfGameOver(string [], bool &);
void checkIfWin(string, string, string, bool &);
void checkIfTie(string [], bool &);
string checkRows(string []);
string checkColumns(string []);
string checkDiagonals(string []);

int main() {
  string board[9];
  for(int i = 0; i < 9; i++)
    board[i] = "-";

  bool status_game = true;
  string player = "X";

  playGame(board, status_game, player);

  return 0;
}

void display_board(string board[])
{
  int count = 0;
  for(int i = 0; i < 9; i++)
  {
    count++;
    if(count == 3)
    {
      cout << board[i] << endl;
      count = 0;
      continue;
    }
    cout << board[i] + " | ";
  }
}

void playGame(string board[], bool &status_game, string player)
{
  display_board(board);
  while(status_game)
  {
    handleTurn(board, player);
   
    checkIfGameOver(board, status_game);
     player = (player == "X")?"O":"X";
     checkIfTie(board, status_game);
     checkIfWin(checkRows(board), checkColumns(board), checkDiagonals(board), status_game);

  }
}

void handleTurn(string board[], string player)
{
  string pos;
  cout << "\n" << player << " turn";
  cout << "\n Choose a position from 1-9 ";
  getline(cin, pos);
  int posInt = atoi(pos.c_str());
  while(posInt > 9 || posInt < 1)
  {
    cout << "\n Choose a position from 1-9 ";
    getline(cin, pos);
  }
  while(board[posInt - 1] != "-")
  {
    cout << "\n Wrong position!, input again ";
    getline(cin, pos);
    posInt = atoi(pos.c_str());
  }
  board[posInt - 1] = player;
  display_board(board);
}

void checkIfGameOver(string board[], bool &status_game)
{
  int count = 0;
  for(int i = 0; i  < 9; i++)
    if(board[i] != "-")
      count++;
  if(count == 9)
    status_game = false;
}

void checkIfWin(string rows, string columns, string diagonals, bool &status_game)
{
  // check rows
  if(rows == "X" or rows == "O")
  {
    winner = rows;
  }
  else if(columns == "X" or columns == "O")
    winner = columns;
  else if(diagonals == "X" or diagonals == "O")
    winner = diagonals;
  
  if(winner == "X" or winner == "O")
  {
    cout << endl << winner << " won.";
    status_game = false;
  }
}

string checkRows(string board[])
{
  bool row_1, row_2, row_3 = false;
  if(board[0] == board[1] && board[1] == board[2])
    row_1 = true;
  if(board[3] == board[4] && board[4] == board[5])
    row_2 = true;
  if(board[6] == board[7] && board[7] == board[8])
    row_3 = true;
  if(row_1)
    return board[0];
  else if(row_2)
    return board[3];
  else if(row_3)
    return board[6];
  return "";
}

string checkColumns(string board[])
{
  bool colum_1, colum_2, colum_3 = false;
  if(board[0] == board[1] && board[1] == board[2])
    colum_1 = true;
  if(board[3] == board[4] && board[4] == board[5])
    colum_2 = true;
  if(board[6] == board[7] && board[7] == board[8])
    colum_3 = true;
  if(colum_1)
    return board[0];
  else if(colum_2)
    return board[3];
  else if(colum_3)
    return board[6];
  return "";
}

string checkDiagonals(string board[])
{
  bool Diagonal_1, Diagonal_2 = false;
  if(board[0] == board[4] && board[4] == board[8])
    Diagonal_1 = true;
  else if(board[2] == board[4] && board[4] == board[6])
    Diagonal_2 = true;
  if(Diagonal_1)
    return board[0];
  else if(Diagonal_2)
    return board[2];
  return "";
}

void checkIfTie(string board[], bool &status_game)
{
  int count = 0;
  for(int i = 0; i < 9; i++)
    if(board[i] != "-")
      count++;
  status_game = (count == 9 && status_game == false)?false:true;
}