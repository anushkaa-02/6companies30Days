#include<bits/c++.h>
using namespace std;

class Solution
{
    public:
    long long countWays(int m)
    {
        long long dp[m+1];
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=m;i++)
        dp[i]=min(dp[i-2],dp[i-1])+1;
        
        return dp[m];
    }
};

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; 
    }
    return 0;
} 
