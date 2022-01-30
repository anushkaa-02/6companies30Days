#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<pair<int, int>> result;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < speed.size(); ++i)
            result.push_back({efficiency[i], speed[i]});
        sort(result.begin(), result.end());
        long long ans = 0, sum = 0, mod = 1e9 + 7;
        for (int i = result.size() - 1; i >= 0; i--)
        {
            pq.push(result[i].second);
            sum += result[i].second;
            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum * result[i].first);
        }
        return ans % mod;
    }
};
