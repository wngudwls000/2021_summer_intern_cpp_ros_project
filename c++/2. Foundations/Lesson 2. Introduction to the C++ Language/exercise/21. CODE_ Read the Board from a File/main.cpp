#include <iostream>
#include <fstream>

#include <string>
#include <vector>
using std::cout;
using std::string;
using std::ifstream;
using std::vector;

// TODO: Add the ReadBoardFile function here.
void ReadBoardFile(string path)
{
  ifstream myfile (path);
  vector<vector<int>> board{};
  if (myfile)
  {
    string line;
    while (getline(myfile, line))
    {
      // vector<int> row = ParseLine(line);
      // board.push_back(row);
            cout << line << "\n";
    }
  }
}

// PrintBoard not used in this exercise
void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

int main() {
  // TODO: Call the ReadBoardFile function here.
    ReadBoardFile("1.board");
    // PrintBoard(board); 
    // Leave the following line commented out.
  //PrintBoard(board);
}