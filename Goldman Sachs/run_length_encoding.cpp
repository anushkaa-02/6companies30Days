#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}

string encode(string src)
{     
  int c=1,n=src.size();
    string ans="";
    ans+=src[0];
    for(int i=1;i<n;i++){
        if(src[i]==src[i-1])
            c++;
        else{
            ans+=c+'0';       
            ans+=src[i];
            c=1;
        }
    }
    ans+=to_string(c);   
    return ans;
}
