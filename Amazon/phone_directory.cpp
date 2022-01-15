#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string str)
    {
        
        vector<vector<string>> ans;
        set<string> s;
        vector<string>v;
        string prefix="";
        
        for(int i=0; i<n; i++)
            v.push_back(contact[i]);
        
        for(int i=0; i<str.length(); i++)
        {
            prefix+= str[i];
        
            for(auto x: v)
            {
                if(x.substr(0,i+1)==prefix)
                    s.insert(x);
            }
            
            if(s.empty())
                s.insert("0");
            
            v.clear();
            v.insert(v.begin(), s.begin(), s.end());
            s.clear();
            ans.push_back(v);
        }
        
        return ans;
    }
};
