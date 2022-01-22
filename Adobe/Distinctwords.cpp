#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
  public:
    int kvowelwords(int N, int K) {
    vector < vector<long long> dp(N + 1, vector < long long(K + 1, 0));

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= K; ++j)
        {

            if (i == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = (dp[i - 1][K] * 21) % 1000000007;

                if (j > 0)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * 5 % 1000000007) % 1000000007;
                }
            }
        }
    }
    return dp[N][K];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
} 
