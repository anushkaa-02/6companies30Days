#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n= arr.size();
        int start=0, ans=0;
        
        while(start<n)
        {
            int end= start;
            int desc=0, asc=0;
            
            while(end+1<n && arr[end+1]>arr[end])
            {  
                end++;
                asc=1;
            }
            
          
            while(end+1<n && arr[end]>arr[end+1])
            {
                end++;
                desc=1;
            }
            
            int mountain_len= end-start+1;
            if(mountain_len!=1 && asc==1 && desc==1)
                ans= max(ans, mountain_len);
            
            if(desc)
                start= end;
            else
                start= end+1;
        }
        
        return ans;
    }
};
