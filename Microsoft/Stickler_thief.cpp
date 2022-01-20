#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
    public:
    int FindMaxSum(int arr[], int n)
    {
          int incl=arr[0];
       int excl=0;
       int new_excl;
       for(int i=1;i<n;i++){
         new_excl=(incl>excl) ? incl : excl;
           incl=excl+arr[i];
           excl=new_excl;
       }
       return ((incl>excl) ? incl : excl);
   
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
