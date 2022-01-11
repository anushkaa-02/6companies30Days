#include<bits/stdc++.h>
using namespace std;
class Solution {
	public:
		string FirstNonRepeating(string A){
		    int t[26];
		    memset(t,0,sizeof t);
		    vector<char> first;
		    string res;
		    for(int i=0;i<A.size();i++){
		        if(t[A[i]-'a']==0) first.push_back(A[i]);
		        t[A[i]-'a']++;
		        int f=0, n=first.size();
		        for(int j=0;j<n;j++){
		            if(t[first[j]-'a']==1){
		                res+=first[j];
		                f=1;
		                break;
		            }
		        }
		        if(f==0) res+='#';
		    }
		    return res;
		}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
