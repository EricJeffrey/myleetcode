#include <algorithm>
#include <array>
#include <bitset>
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
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int minCapability(vector<int> &nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        auto check = [&nums, &dp](int x) {
            fill(dp.begin(), dp.end(), vector<int>(2, 0));
            dp[0] = {0, nums[0] <= x ? 1 : 0};
            if (nums.size() > 1) {
                dp[1] = {dp[0][1], nums[1] <= x ? 1 : 0};
            }
            for (int i = 2; i < nums.size(); i++) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = (nums[i] <= x ? max(dp[i - 2][0], dp[i - 2][1]) + 1 : 0);
            }
            return max(dp.back()[0], dp.back()[1]);
        };
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = (l + r) / 2;
            int tmpk = check(mid);
            if (tmpk >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};