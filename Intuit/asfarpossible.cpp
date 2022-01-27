#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int res = -1, n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n + 2, vector<int>(m + 2, 1e9));
        bool p = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (grid[i - 1][j - 1] == 1)
                {
                    dp[i][j] = 0;
                    p = 1;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + 1;
                }
            }
            for (int j = m; j >= 0; j--)
            {
                dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            }
        }
        if (!p)
            return -1;
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
            for (int i = n; i >= 0; i--)
            {
                dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (grid[i - 1][j - 1] == 0)
                {
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};
