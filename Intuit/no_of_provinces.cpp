#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(vector<vector<int>> &graph, vector<bool> &visited, int city)
  {
    if (visited[city])
      return;
    visited[city] = true;
    for (int i = 0; i < graph[city].size(); i++)
    {
      if (graph[city][i])
        dfs(graph, visited, i);
    }
  }

  int findCircleNum(vector<vector<int>> &graph)
  {
    int cities = graph.size();
    int count = 0;
    vector<bool> visited(cities, false);
    for (int i = 0; i < cities; i++)
    {
      if (visited[i])
        continue;
      count++;
      dfs(graph, visited, i);
    }
    return count;
  }
};
