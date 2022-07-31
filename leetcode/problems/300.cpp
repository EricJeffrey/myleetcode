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
  public:
    // O(n^2)
    int lengthOfLIS(vector<int> &nums) {
        const int n = nums.size();
        if (n <= 1)
            return n;
        int dp[n + 1] = {1}, res = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--)
                nums[j] < nums[i] ? dp[i] = max(dp[i], dp[j] + 1) : 0;
            res = max(res, dp[i]);
        }
        return res;
    }
    // O(nlogn)
    int lenOfLIS(vector<int> &nums) {
        const int n = nums.size();
        if (n <= 1)
            return n;
        int dp[n + 1] = {0, nums[0]}, m = 1;
        for (int i = 1; i < n; i++) {
            const int who = nums[i];
            int x = lower_bound(dp + 1, dp + m + 1, who) - dp;
            dp[x] = who;
            m = max(x, m);
        }
        return m;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums = {4, 2, 3, 1, 6, 8, 1, 7, 2, 5, 9};
    cout << Solution().lenOfLIS(nums) << endl;
    return 0;
}
