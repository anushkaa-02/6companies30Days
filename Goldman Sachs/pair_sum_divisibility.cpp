#include <bits/stdc++.h>
using namespace std;

bool canPairs(int arr[], int n, int k)
{
    if (n & 1)
        return false;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[((arr[i] % k) + k) % k]++;
    for (int i = 0; i < n; i++) {
        int rem = ((arr[i] % k) + k) % k;
        if (2 * rem == k) {
            if (freq[rem] % 2 != 0)
                return false;
        }
        else if (rem == 0) {
            if (freq[rem] & 1)
                return false;
        }
        else if (freq[rem] != freq[k - rem])
            return false;
    }
    return true;
}
int main()
{
    int arr[] = { 82, 40, 69, 91, 55, 25 };
    int k = 10;
    int n = sizeof(arr) / sizeof(int);
    canPairs(arr, n, k) ? cout << "True" : cout << "False";
    return 0;
}
