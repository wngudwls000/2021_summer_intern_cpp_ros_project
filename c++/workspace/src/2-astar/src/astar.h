#ifndef ASTAR_H
#define ASTAR_H

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

class Astar {
    public:
    Astar(string p, int i[2], int g[2]) : path(p)
    {
        path = p;
        init[2] = i[2];
        goal[2] = g[2];
    }
    vector<State> ParseLine(string line);
    void ReadBoardFile();
    static bool Compare(const vector<int> node1, const vector<int> node2);
    void CellSort(vector<vector<int>> *v);
    int Heuristic(int x1, int y1, int x2, int y2);
    bool CheckValidCell(int x, int y, vector<vector<State>> &grid);
    void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid);
    void ExpandNeighbors(const vector<int> &current_node, vector<vector<int>> &open, vector<vector<State>> &grid, int goal[2]);
    void Search();
    string CellString(State cell);
    void PrintBoard();
    void PrintSolution();
    
    private:
    // directional deltas
    const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    string path;
    int init[2];
    int goal[2];
    vector<vector<State>> grid{};
    vector<vector<State>> solution{};
};

#endif