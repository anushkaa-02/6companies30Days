#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string nextPalin(string N)
    {
        int i = 0, j = 0, n = N.length();
        string s = N;
        i = n / 2 - 2;
        if (i < 0)
            return "-1";

        while (i >= 0 && s[i] - '0' >= s[i + 1] - '0')
        {
            i--;
        }

        if (i < 0)
            return "-1";

        j = n / 2 - 1;

        while (s[j] - '0' <= s[i] - '0')
            j--;

        swap(s[i], s[j]);

        int k = i + 1;
        j = n / 2 - 1;

        while (k <= j)
        {
            swap(s[k++], s[j--]);
        }

        while (i <= n / 2 - 1)
        {
            s[n - i - 1] = s[i];
            i++;
        }

        return s;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
} 
