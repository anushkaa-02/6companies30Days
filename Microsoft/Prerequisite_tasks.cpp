#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	   vector<int> g[N];
	    for(auto i : pre){
	        g[i.first].push_back(i.second);
	    }
	   vector<int> vis(N,0);
	   for(int i=0;i<N;i++){
	       if(vis[i]==0 )
	       if(check_loop(i,vis,g)){
	           return false;
	       }
	   }
	   return true;
	}
	
	bool check_loop(int i , vector<int> &vis,vector<int> g[]){
	    vis[i]=2;
	    for(auto nbr:g[i]){
	        if(vis[nbr]==2) return true;
	        
	        if(vis[nbr]==0)
	          if(check_loop(nbr,vis,g)){
	            return true;
	        }
	    }
	    
	    vis[i]=1;
	    return false;
	}
	
};

int main()
{
	int tc;
	cin>>tc;
	while(tc--){
		int N,P;
		vactor<pair<int, int> > prerequisites;
		cin>>N;
		cin>>P;
		for (int i=0;i<P;i++){
			int x,y;
			cin>>x>>y;
			prerequisites.push_back(make_pair(x,y));
		}
		
		Solution ob;
		if (ob.isPossible(N, prerequisites))
			cout<< "Yes";
		else
			cout<< "No";
		cout<<endl;
	}
	return 0;
}
