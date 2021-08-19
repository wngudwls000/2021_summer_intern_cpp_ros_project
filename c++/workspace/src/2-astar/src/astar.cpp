#include "astar.h"
#include <vector>
using std::vector;

vector<State> Astar::ParseLine(string line)
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

void Astar::ReadBoardFile()
{
    ifstream myfile (path);
    if (myfile)
    {
        string line;
        while (getline(myfile, line))
        {
        vector<State> row = ParseLine(line);
        grid.push_back(row);
        }
    }
}


// Compare the F values of two cells.
bool Astar::Compare(const vector<int> node1, const vector<int> node2)
{
    int f1 = node1[2] + node1[3]; // f1 = g1 + h1
    int f2 = node2[2] + node2[3]; // f2 = g2 + h2

    if(f1 > f2)
        return true;
    else
        return false;
}

void Astar::CellSort(vector<vector<int>> *v) 
{
    sort(v->begin(), v->end(), Compare);
}


// Calculate the manhattan distance
int Astar::Heuristic(int x1, int y1, int x2, int y2)
{
    return (abs(x2 - x1) + abs(y2 - y1));
}


// Check that the cell is on the grid and not an obstacle (i.e. equals kEmpty).
bool Astar::CheckValidCell(int x, int y, vector<vector<State>> &grid)
{
    if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == State::kEmpty)
    {
        return true;
    }
    else
        return false;
}


// Add a node to the open list and mark it as open. 
void Astar::AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid)
{
    // Add node to open vector, and mark grid cell as closed.
    vector<int> open_vector = {x, y, g, h};
    openlist.push_back(open_vector);
    grid[x][y] = State::kClosed;
}


// Expand current nodes's neighbors and add them to the open list.
void Astar::ExpandNeighbors(const vector<int> &current_node, vector<vector<int>> &open, vector<vector<State>> &grid, int goal[2])
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
void Astar::Search()
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
            solution = grid;
        }
        else
        {
            // If we're not done, expand search to current node's neighbors.
            ExpandNeighbors(current_node, open, grid, goal);
        }
    }

    // We've run out of new nodes to explore and haven't found a path.
    cout << "No path found!" << "\n";
    solution = vector<vector<State>>{};
}


string Astar::CellString(State cell)
{
    switch(cell) {
        case State::kObstacle: return "⛰️   ";
        case State::kPath: return "🚗   ";
        case State::kStart: return "🚦   ";
        case State::kFinish: return "🏁   ";
        default: return "0   "; 
    }
}


void Astar::PrintBoard()
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            cout << CellString(grid[i][j]);
        }
        cout << "\n";
    }
}

void Astar::PrintSolution()
{
    for (int i = 0; i < solution.size(); i++)
    {
        for (int j = 0; j < solution[i].size(); j++)
        {
            cout << CellString(solution[i][j]);
        }
        cout << "\n";
    }
}