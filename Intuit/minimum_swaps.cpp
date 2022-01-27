#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
public:
  int minSwaps(vector<vector<int>> &grid)
  {
    int n = grid.size();
    vector<int> countArr;

    for (int i = 0; i < n; i++)
    {
      int count = 0;
      for (int j = n - 1; j >= 0; j--)
      {
        if (grid[i][j] == 0)
          count++;
        else
          break;
      }
      countArr.push_back(count);
    }

    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
      if (countArr[i] >= n - i - 1)
        continue;

      int j = i + 1;
      while (j < n)
      {
        if (countArr[j] >= n - i - 1)
          break;
        j++;
      }
      if (j == n)
        return -1;

      while (i < j)
      {
        swaps++;
        swap(countArr[j], countArr[j - 1]);
        j--;
      }
    }
    return swaps;
  }
};
