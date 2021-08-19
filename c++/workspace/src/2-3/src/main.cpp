#include <algorithm>  // for sort
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;
using std::abs;

enum class State {kEmpty, kObstacle, kClosed, kPath, kStart, kFinish};

// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

vector<State> ParseLine(string line)
{
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',')
    {
      if (n == 0)
      {
        row.push_back(State::kEmpty);
      } else
      {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}


vector<vector<State>> ReadBoardFile(string path)
{
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile)
  {
    string line;
    while (getline(myfile, line))
    {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}


// Compare the F values of two cells.
bool Compare(const vector<int> node1, const vector<int> node2)
{
  int f1 = node1[2] + node1[3]; // f1 = g1 + h1
  int f2 = node2[2] + node2[3]; // f2 = g2 + h2

  if(f1 > f2)
    return true;
  else
    return false;
}


// Sort the two-dimensional vector of ints in descending order. ex(5,4,3,2,1)
void CellSort(vector<vector<int>> *v) 
{
  sort(v->begin(), v->end(), Compare);
}


// Calculate the manhattan distance
int Heuristic(int x1, int y1, int x2, int y2)
{
  return (abs(x2 - x1) + abs(y2 - y1));
}


// Check that the cell is on the grid and not an obstacle (i.e. equals kEmpty).
bool CheckValidCell(int x, int y, vector<vector<State>> &grid)
{
  if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == State::kEmpty)
  {
    return true;
  }
  else
    return false;
}


// Add a node to the open list and mark it as open. 
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid)
{
  // Add node to open vector, and mark grid cell as closed.
  vector<int> open_vector = {x, y, g, h};
  openlist.push_back(open_vector);
  grid[x][y] = State::kClosed;
}


// Expand current nodes's neighbors and add them to the open list.
void ExpandNeighbors(const vector<int> &current_node, vector<vector<int>> &open, vector<vector<State>> &grid, int goal[2])
{
  // Get current node's data.
  auto cur_node = current_node;

  // Loop through current node's potential neighbors.
  for(int i = 0; i < 4; i++)
  {
      cur_node[0] = cur_node[0] + delta[i][0];
      cur_node[1] = cur_node[1] + delta[i][1];

      // Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
      if(CheckValidCell(cur_node[0], cur_node[1], grid))
      {
        // Increment g value and add neighbor to open list.
        cur_node[2]++;
        cur_node[3] = Heuristic(cur_node[0], cur_node[1], goal[0], goal[1]);
        AddToOpen(cur_node[0], cur_node[1], cur_node[2], cur_node[3], open, grid);
      }
    cur_node = current_node;
  }
} 


// Implementation of A* search algorithm
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2])
{
  // Create the vector of open nodes.
  vector<vector<int>> open{};

  // Initialize the starting node. 
  int x = init[0];
  int y = init[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0], goal[1]);
  AddToOpen(x, y, g, h, open, grid);

  while(open.size() > 0)
  {
    // Get the next node
    CellSort(&open);
    auto current_node = open.back();
    open.pop_back();
    x = current_node[0];
    y = current_node[1];
    grid[x][y] = State::kPath;

    // Check if we're done.
    if(x == goal[0] && y == goal[1])
    {
      //Set the init grid cell to kStart, and set the goal grid cell to kFinish before returning the grid. 
      grid[init[0]][init[1]] = State::kStart;
      grid[goal[0]][goal[1]] = State::kFinish;
      return grid;
    }
    else
    {
    // If we're not done, expand search to current node's neighbors.
    ExpandNeighbors(current_node, open, grid, goal);
    }
  }

  // We've run out of new nodes to explore and haven't found a path.
  cout << "No path found!" << "\n";
  return vector<vector<State>>{};
}


string CellString(State cell)
{
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    case State::kPath: return "🚗   ";
    case State::kStart: return "🚦   ";
    case State::kFinish: return "🏁   ";
    default: return "0   "; 
  }
}


void PrintBoard(const vector<vector<State>> board)
{
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[i].size(); j++)
    {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}


int main()
{
  // Declare "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
  int init[2]{0, 0};
  int goal[2]{4, 5};

  auto board = ReadBoardFile("1.board");

  // Call Search with "board", "init", and "goal". Store the results in the variable "solution".
  // Change the following line to pass "solution" to PrintBoard.
  auto solution = Search(board, init, goal);
  PrintBoard(solution);
}
