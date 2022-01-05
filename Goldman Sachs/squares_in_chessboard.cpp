#include <bits/stdc++.h>
using namespace std;
int store(int n)
{
    return(n*(n+1)/2) * (2*n+1)/3;
}
int main()
{
    int n;
    cin>>n;
    cout<<store(n)<<endl;
    return 0;
}
