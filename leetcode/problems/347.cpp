
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        for (auto &&tmp : nums) {
            m[tmp]++;
        }
        vector<int> res;
        priority_queue<pair<int, int>> q;
        for (auto it = m.begin(); it != m.end(); it++) {
            q.push(make_pair(it->second, it->first));
            if (q.size() > m.size() - k) {
                res.push_back(q.top().second);
                q.pop();
            }
        }
        return res;
    }
};

int main() {}
