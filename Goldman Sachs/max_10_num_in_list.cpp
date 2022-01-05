#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class solution
{
public:
    vector<int> findKthLargest(vector<int> &nums, int k)
    {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
int main()
{
    vector<int> v{100002000, 3, 8, 9, 10, 850, 24, 200, 2, 4, 700, 1000};
    solution s;

    vector<int> res = s.findKthLargest(v, 3);
    for (auto i : res)
        cout << i << " ";
    return 0;
}
