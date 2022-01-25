#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  Node *solve(vector<vector<int>> &grid, int rowStart, int colStart, int width)
  {
    int sum = 0;
    int rowEnd = rowStart + width;
    int colEnd = colStart + width;
    for (int i = rowStart; i < rowEnd; i++)
    {
      for (int j = colStart; j < colEnd; j++)
      {
        sum += grid[i][j];
      }
    }

    if (sum == 0)
    {
      return new Node(0, true);
    }
    if (sum == width * width)
    {
      return new Node(1, true);
    }

    Node *root = new Node(0, false);
    width = width / 2;
    root->topLeft = solve(grid, rowStart, colStart, width);
    root->topRight = solve(grid, rowStart, colStart + width, width);
    root->bottomLeft = solve(grid, rowStart + width, colStart, width);
    root->bottomRight = solve(grid, rowStart + width, colStart + width, width);
    return root;
  }

  Node *construct(vector<vector<int>> &grid)
  {
    int n = grid.size();
    return solve(grid, 0, 0, n);
  }
};
