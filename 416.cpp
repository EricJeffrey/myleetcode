#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
  private:
    int cursum;

  public:
    bool canPartition(vector<int> &nums) {
        int target = 0;
        for (int v : nums)
            target += v;
        if (nums.size() <= 1 || target & 1)
            return false;
        target >>= 1;
        // 也可以记忆化搜索
        return dp(nums, target);
    }
    bool dp(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        bool dp[target + 1] = {1};
        for (int v : nums) {
            if (v > target)
                continue;
            if (v == target)
                return true;
            for (int j = target; j >= v; j--)
                dp[j] = (dp[j - v] == 1 ? 1 : dp[j]);
        }
        return dp[target] == 1;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> nums;
    nums = {6, 6, 8, 3, 3, 1, 5};
    // nums =
    // {18, 40, 62, 33, 83, 64, 10, 92, 67, 31, 42, 51, 10, 97, 41, 7, 82,
    //         71, 80, 81, 41, 38, 88, 25, 38, 89, 24,  89, 90, 12, 97,
    //         21, 22, 85, 11, 59, 83, 6,  51, 47, 32, 82, 83, 100, 29,
    //         78, 36, 32, 1,  31, 36, 19, 35, 3,  36, 21, 24, 93, 42,
    //         33, 10,  26, 2,  39, 36, 62, 85, 24, 41, 5,  66, 53, 7,
    //         1,  59, 53, 40, 59,  41, 95, 7,  67, 20, 29, 80, 59, 49,
    //         49, 51, 90, 13, 52, 6,  90, 5,   6,  31, 81, 95, 26};
    // nums =
    // {71, 70, 66, 54, 32, 63, 38, 98, 4,  22, 61, 40, 6,  8,  6,  21,
    // 71,
    //         36, 30, 34, 44, 60, 89, 53, 60, 56, 73, 14, 63, 37, 15,
    //         58, 51, 88, 88, 32, 80, 32, 10, 89, 67, 29, 68, 65, 34,
    //         15, 88, 8,  57, 78, 37, 63, 73, 65, 47, 39, 32, 74, 31,
    //         44, 43, 4,  10, 8,  96, 22, 58, 87, 29, 99, 79, 13, 96,
    //         21, 62, 71, 34, 55, 72, 3,  96, 7,  36, 64, 30, 6,  14,
    //         87, 12, 90, 40, 13, 29, 21, 94, 33, 99, 86, 4,  100};
    cout << Solution().canPartition(nums) << endl;
    return 0;
}
