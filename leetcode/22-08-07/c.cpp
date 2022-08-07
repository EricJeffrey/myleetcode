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
    bool validPartition(vector<int> &nums) {
        vector<bool> dp(nums.size(), false);
        if (nums[0] == nums[1])
            dp[1] = true;
        if (nums.size() > 2 && nums[0] == nums[1] && nums[1] == nums[2])
            dp[2] = true;
        if (nums.size() > 2 && nums[1] - nums[0] == 1 && nums[2] - nums[1] == 1)
            dp[2] = true;
        if (dp[1] == false && dp[2] == false)
            return false;
        for (size_t i = 3; i < dp.size(); i++) {
            if (nums[i] == nums[i - 1])
                dp[i] = dp[i] || dp[i - 2];
            if (nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2])
                dp[i] = dp[i] || dp[i - 3];
            if (nums[i] - nums[i - 1] == 1 && nums[i - 1] - nums[i - 2] == 1)
                dp[i] = dp[i] || dp[i - 3];
        }
        return dp.back();
    }
};