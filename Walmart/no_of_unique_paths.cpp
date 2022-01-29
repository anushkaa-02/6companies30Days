#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int NumberOfPath(int a, int b)
    {
        int N = a+b-2;
       int r= a-1;
       double res = 1;
       for(int i=1;i<=r;i++){
           res = res * (N-r+i)/i;
       }
       return (int)res;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        Solution ob;
        cout << ob.NumberOfPath(a,b) << endl;
    }
}
