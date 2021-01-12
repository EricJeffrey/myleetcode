#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // 分块
        if (k == 0 || nums.empty() || nums.size() < k)
            return {};
        const int sz = nums.size();
        vector<int> res(sz - k + 1, 0), lKMax(sz, 0), rKMax(sz, 0);
        for (int i = 0; i < sz; i++) {
            if (i % k == 0)
                lKMax[i] = nums[i];
            else
                lKMax[i] = max(lKMax[i - 1], nums[i]);
        }
        rKMax[sz - 1] = nums[sz - 1];
        for (int i = sz - 2; i >= 0; i--) {
            if (i % k == 0)
                rKMax[i] = nums[i];
            else
                rKMax[i] = max(rKMax[i + 1], nums[i]);
        }
        for (int i = 0; i < sz - k + 1; i++) {
            res[i] = max(rKMax[i], lKMax[i + k - 1]);
        }
        return res;
    }
    vector<int> maxSlidingWindow1(vector<int> &nums, int k) {
        // 队列法
        if (k == 0 || nums.empty() || nums.size() < k)
            return {};
        const int sz = nums.size();
        vector<int> res;
        res.reserve(sz - k + 1);
        deque<int> q;
        for (int i = 0; i < sz; i++) {
            while (!q.empty() && q.front() < i - k + 1)
                q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
            if (i >= k - 1)
                res.push_back(nums[q.front()]);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    auto testout = [](vector<int> nums, int k) {
        auto res = Solution().maxSlidingWindow(nums, k);
        for (auto &&v : res) {
            cout << v << ", ";
        }
        cout << endl;
    };
    testout({2, 6, 1, 12, 10, 9, 2, 1, 7, 12}, 4);
    testout({1, 3, -1, -3, 5, 3, 6, 7}, 3);
    testout({1, 3, -1, -3, 5}, 1);
    testout({1, 3, -1, -3, 5}, 2);
    testout({1, 3, -1, -3, 5}, 5);
    return 0;
}
