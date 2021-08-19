#include "astar.h"

int main()
{
  // Declare "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
  int init[2]{0, 0};
  int goal[2]{4, 5};

  Astar astar = Astar("1.board", init, goal);

  astar.ReadBoardFile();
  astar.Search();
  astar.PrintSolution();

}
