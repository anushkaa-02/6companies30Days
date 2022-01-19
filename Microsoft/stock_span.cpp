#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
       stack<pair<int,int>> s;
       s.push({0,price[0]});
       
       int i = 1;
       vector<int> ans;
       ans.push_back(1);
       while(i<n){
           while(!s.empty() && s.top().second<=price[i]){
               s.pop();
           }
           if(!s.empty())
           ans.push_back(i-s.top().first);
           else
           ans.push_back(i+1);
           
           s.push({i,price[i]});
           i++;
       }
       
       return ans;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
