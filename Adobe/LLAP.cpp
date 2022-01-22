#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n){
    if (n <= 2)
    return n;
    int mp[n][n];
    int ans = 2;
    for (int i = 0; i < n; i++)
        mp[i][n - 1] = 2;

    for (int j = n - 2; j >= 1; j--)
    {
        int i = j - 1, k = j + 1;
        while (i >= 0 && k <= n - 1)
        {
            if (A[i] + A[k] < 2 * A[j])
                k++;

            else if (A[i] + A[k] > 2 * A[j])
            {
                mp[i][j] = 2, i--;
            }

            else
            {
                mp[i][j] = mp[j][k] + 1;

                ans = max(ans, mp[i][j]);
                i--;
                k++;
            }
        }

        while (i >= 0)
        {
            mp[i][j] = 2;
            i--;
        }
    }
    return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
