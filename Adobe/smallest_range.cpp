#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int find(vector<int>& ans,int num){
        int s=0,e=ans.size()-1,res=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(ans[mid]>=num){
                res=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return res;
    }
    int LIS(vector<int>& v){
        int n=v.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(ans.size()==0) ans.push_back(v[i]);
            else if(v[i]>ans.back()) ans.push_back(v[i]);
            else{
                int idx=find(ans,v[i]);
                ans[idx]=v[i];
            }
        }
        return ans.size();
    }
    int minInsAndDel(int a[], int b[], int n, int m) {
        unordered_set<int> mp;
        for(int i=0;i<m;i++) mp.insert(b[i]);
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(mp.find(a[i])!=mp.end()) temp.push_back(a[i]);
        }
        int lis=LIS(temp);
        return n+m-2*lis;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
} 
