#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &pre)
  {
    int inward[numCourses];
    memset(inward, 0, sizeof(inward));
    vector<int> graph[numCourses];

    for (int i = 0; i < pre.size(); i++)
    {
      inward[pre[i][0]]++;
      graph[pre[i][1]].push_back(pre[i][0]);
    }

    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < numCourses; i++)
    {
      if (inward[i] == 0)
      {
        ans.push_back(i);
        q.push(i);
      }
    }

    while (!q.empty())
    {
      int front = q.front();
      q.pop();
      for (auto &ele : graph[front])
      {
        inward[ele]--;
        if (inward[ele] == 0)
        {
          ans.push_back(ele);
          q.push(ele);
        }
      }
    }

    if (ans.size() != numCourses)
      return {};
    return ans;
  }
};
