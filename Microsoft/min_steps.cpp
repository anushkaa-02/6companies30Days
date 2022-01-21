#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
int solve(int src, int ctr, int dest){
        if(abs(src) > (dest)){
            return INT_MAX;
        }
        if(src == dest){
            return ctr-1;
        }
        int l = solve(src+ctr,ctr+1,dest);
        int r = solve(src-ctr,ctr+1,dest);
        return min(l,r);
    }
    int minSteps(int D){
        int x = solve(0,1,D);
        return x;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
} 
