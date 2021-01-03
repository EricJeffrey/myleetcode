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

const size_t maxval = 101;
using TwoDInt = vector<vector<int>>;

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        const size_t sz = nums.size();
#define multi(i, j, k) ((i > 0 ? nums[i - 1] : 1) * nums[k] * (j < sz - 1 ? nums[j + 1] : 1))
        if (sz == 0)
            return 0;
        else if (sz == 1)
            return nums[0];
        else if (sz == 2)
            return nums[0] * nums[1] + max(nums[0], nums[1]);
        int dp[501][501] = {};
        for (int i = sz - 1; i >= 0; i--) {
            dp[i][i] = multi(i, i, i);
            for (size_t j = i; j < sz; j++) {
                for (size_t k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], (k > 0 ? dp[i][k - 1] : 0) +
                                                 (k < sz - 1 ? dp[k + 1][j] : 0) + multi(i, j, k));
                }
            }
        }
#undef multi
        return dp[0][sz - 1];
    }
};

int main(int argc, char const *argv[]) {
    auto runtest = [](vector<int> nums) { cout << Solution().maxCoins(nums) << endl; };
    runtest({3, 1, 5, 8});    // 167
    runtest({3, 6, 7, 2, 9}); // 702
    runtest({
        3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1,
        5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8,
        3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1,
        5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8,
        5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8,
        3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1,
        5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8,
        5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8,
        3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1,
        5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8,
        3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1,
        5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8,
        5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8,
        3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1,
        5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8,
        5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8, 3, 1, 5, 8,
    }); // 57725
    return 0;
}
