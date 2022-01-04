#include <bits/stdc++.h>
using namespace std;

int lastPosition(int n, int m, int k)
{
    if (m <= n - k + 1)
    return m + k - 1;

    m = m - (n - k + 1);
    return (m % n == 0) ? n : (m % n);
}

int main()
{
    int n,m,k;
    cout<<"Enter the value of N: ";
    cin>>n;
    cout<<"Enter the value of M: ";
    cin>>m;
    cout<<"Enter the value of K: ";
    cin>>k;  
    cout << lastPosition(n, m, k);
    return 0;
}
