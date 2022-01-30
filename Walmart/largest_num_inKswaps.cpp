#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(string str, int index, int k, string &res)
    {
        if (k == 0 || index == str.length())
            return;
        char c = str[index];
        for (int i = index + 1; i < str.length(); i++)
        {
            if (str[i] > c)
                c = str[i];
        }
        if (c != str[index])
            k--;
        for (int i = str.length() - 1; i >= index; i--)
        {
            if (str[i] == c)
            {
                swap(str[i], str[index]);
                res = max(res, str);
                solve(str, index + 1, k, res);
                swap(str[i], str[index]);
            }
        }
    }

    string findMaximumNum(string str, int k)
    {
        string res = str;
        solve(str, 0, k, res);
        return res;
    }
};
int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
