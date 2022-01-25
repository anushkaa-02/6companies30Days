#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(vector<vector<int>> &heights, int i, int j, vector<vector<bool>> &visited, int prev)
  {
    int m = heights.size(), n = heights[0].size();

    if (i < 0 || j < 0 || i >= m || j >= n)
      return;
    if (heights[i][j] < prev)
      return;
    if (visited[i][j])
      return;
    visited[i][j] = true;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
    for (int k = 0; k < 4; k++)
    {
      dfs(heights, i + dx[k], j + dy[k], visited, heights[i][j]);
    }
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
  {

    int m = heights.size(), n = heights[0].size();

    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
      dfs(heights, i, 0, pacific, INT_MIN);
      dfs(heights, i, n - 1, atlantic, INT_MIN);
    }
    for (int i = 0; i < n; i++)
    {
      dfs(heights, 0, i, pacific, INT_MIN);
      dfs(heights, m - 1, i, atlantic, INT_MIN);
    }

    vector<vector<int>> ans;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (pacific[i][j] && atlantic[i][j])
          ans.push_back({i, j});
      }
    }

    return ans;
  }
};
