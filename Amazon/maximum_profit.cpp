#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        
        int dp[K+1][N];
       memset(dp,0,sizeof(dp));
       for(int i=1;i<=K;i++)
       {
           int mx=INT_MIN;
           for(int j=1;j<N;j++)
           {
               mx=max(mx,dp[i-1][j-1]-A[j-1]);
               dp[i][j]=max(dp[i][j-1],mx+A[j]);
           }
       }
       return dp[K][N-1];
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N,K;
		cin>>K;
		cin>>N;
		int A[N];
		for (int i=0; i<N; i++)
		cin>>A[i];
		Solution ob;
		cout<<ob.maxProfit(K,N,A)<<endl;
	}
	return 0;
	
}
