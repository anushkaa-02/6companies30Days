#include<bits/stdc++.h>
using namespace std;

vector<string> generate(int N)
{
	
	vector<string>res ;
	queue<string>q;
	q.push("1");
	for(int count=0 ; count<N ; count++){
	    string curr = q.front();
	    res.push_back(curr);
	    q.pop();
	    q.push(curr + '0');
	    q.push(curr + '1');
	}
	return res ;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  
