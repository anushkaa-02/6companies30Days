#include <bits/stdc++.h>
using namespace std;
    

class Solution{
    
    public:
    vector<int> leaders(int a[], int n){
        vector<int> vec;
      int mx = a[n-1];
      vec.push_back(mx);
      for(int i=n-2; i>=0; i--){
          if(a[i]>=mx)
          {
              vec.push_back(a[i]);
          }
          mx = max(a[i],mx);
      }
      int i=0;
      int j = vec.size()-1;
      while(i<j)
      {
          swap(vec[i],vec[j]);
          i++;
          j--;
      }
      return vec;
    }
};

int main()
{
   long long t;
   cin >> t;
   while (t--)
   {
       long long n;
       cin >> n;
        
        int a[n];
    
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        vector<int> v = obj.leaders(a, n);
        
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  
