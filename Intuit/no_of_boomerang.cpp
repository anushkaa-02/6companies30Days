#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numberOfBoomerangs(vector<vector<int>> &points)
  {
    unordered_map<int, int> Map;
    int count = 0;
    for (int i = 0; i < points.size(); i++)
    {
      for (int j = 0; j < points.size(); j++)
      {
        if (i == j)
          continue;

        int dist = pow(points[j][1] - points[i][1], 2) + pow(points[j][0] - points[i][0], 2);
        Map[dist]++;
      }
      for (auto &ele : Map)
      {
        count += ele.second * (ele.second - 1);
      }
      Map.clear();
    }
    return count;
  }
};
