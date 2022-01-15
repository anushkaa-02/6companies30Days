#include<bits/stdc++.h>
using namespace std;
string columnTitle(int n)
{
    string ans="";
    while(n>0)
    {
        int x=n%26;
        if(x==0)
        {
            ans='Z'+ans;
            n=(n/26)-1;
        }
        else{
            ans=char('A'+(x-1))+ans;
            n/=26;
        }
    }
    return ans;
}
    
int main()
{
    cout<<"Enter the number: "<<endl;
    int n;
    cin>>n;
    cout<<columnTitle(n);
    return 0;
}