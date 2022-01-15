#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    
    int dp[27][27];
    int bracket[27][27];
    string str;
    char ch;
    
    void printParenthesis(int i, int j)
    {
            
        	if (i == j){
        		str += ch;
        		ch++;
        		return;
        	}
        	str += '(';
        	printParenthesis(i, bracket[i][j]);
        	printParenthesis(bracket[i][j] + 1, j);
        	str += ')';
    }
    
    int solve( int arr[], int i, int j)
    {
        if(i>=j) return 0;
        
        if(dp[i][j]!=-1) 
        {
            return dp[i][j];
        }
        
        int ans= INT_MAX;
        for(int k=i; k<=j-1; k++)
        {
            int temp= solve(arr, i, k)+ solve(arr, k+1, j)+ (arr[i-1]*arr[k]*arr[j]);
            
            if(temp<ans)
            {
                ans= temp;
                bracket[i][j]= k;
            }
        }
        
        dp[i][j]= ans;
        return ans;
    }
    
    string matrixChainOrder(int p[], int n){
       
       memset(dp, -1, sizeof(dp));
       memset(bracket, -1, sizeof(bracket));
       
       int cost= solve(p, 1, n-1);
       
       ch = 'A';
       str="";
       printParenthesis(1, n-1);
       return str; 
       
    }
};
