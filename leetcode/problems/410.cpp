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

class Solution1 {
public:
    int splitArray(vector<int> &nums, int m) {
        const size_t n = nums.size();
        vector<int> dpLast(n, 0);
        vector<int> dp(n, 0);
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for (size_t i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        for (size_t i = 0; i < n; i++) {
            dpLast[i] = prefix[i];
        }
        for (int j = 2; j <= m; j++) {
            for (size_t i = 0; i < n; i++) {
                int tmpv = INT32_MAX;
                for (size_t k = 0; k <= i; k++) {
                    tmpv = min(tmpv, max(dpLast[k], prefix[i] - prefix[k]));
                }
                dp[i] = tmpv;
            }
            dpLast = dp;
            dp = vector<int>(n, 0);
        }
        return dpLast.back();
    }
};

class Solution {
public:
    bool check(int vMax, int m, const vector<int> &nums) {
        int curSum = 0;
        int curNeeds = 0;
        for (auto &&v : nums) {
            if (v > vMax) {
                return false;
            }
            if (curSum + v > vMax) {
                curSum = v;
                curNeeds += 1;
            } else {
                curSum += v;
            }
            if (curNeeds > m) {
                return false;
            }
        }
        curNeeds += 1;
        return curNeeds <= m;
    }
    int splitArray(vector<int> &nums, int m) {
        int l = 0, r = 1e9 + 7;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid, m, nums)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main(int argc, char const *argv[]) {
    int m;
    vector<int> nums;
    m = 2;
    nums = {7, 2, 5, 10, 8};
    cout << Solution().splitArray(nums, m) << endl;
    m = 2;
    nums = {1, 2, 3, 4, 5};
    cout << Solution().splitArray(nums, m) << endl;
    m = 3;
    nums = {1, 4, 4};
    cout << Solution().splitArray(nums, m) << endl;
    m = 4;
    nums = {2, 5, 9, 3, 8, 1, 4};
    cout << Solution().splitArray(nums, m) << endl;
    m = 1;
    nums = {0};
    cout << Solution().splitArray(nums, m) << endl;
    return 0;
}
