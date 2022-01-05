#include <bits/stdc++.h>
using namespace std;
int minSubArraySum(vector<int> arr, int k)
{
    int left=0;
    int result=INT_MAX;
    int val_sum=0;
    for(int i=0; i<arr.size(); i++)
    {
        val_sum+=arr[i];
        while(val_sum>=k)
        {
            result=min(result,i+1-left);
            val_sum-=arr[left];
            left++;
        }
    }
    return result;
}
int main()
{
    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    vector<int> arr;
     for(int i=0; i<n; i++)
    {
        int z;
        cin>>z;
        arr.push_back(z);
    }
    int k;
    cout<<"enter the sum: "<<endl;
    cin>>k;
    cout<<minSubArraySum(arr,k)<<endl;
    return 0;
}
