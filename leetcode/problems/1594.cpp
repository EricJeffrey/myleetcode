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
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>> &grid) {
        const int mod = 1e9 + 7;
        const size_t n = grid.size();
        const size_t m = grid[0].size();
        struct ValType {
            long long minval, maxval;
            ValType() { minval = maxval = 0; }
        };
        vector<vector<ValType>> dp(n);
        for (auto &&x : dp)
            x.resize(m);
        dp[0][0].minval = dp[0][0].maxval = grid[0][0];
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                const int tmpv = grid[i][j];
                if (tmpv > 0) {
                    if (i == 0 || j == 0) {
                        dp[i][j].minval = (i == 0 ? dp[i][j - 1] : dp[i - 1][j]).minval * tmpv;
                        dp[i][j].maxval = (i == 0 ? dp[i][j - 1] : dp[i - 1][j]).maxval * tmpv;
                    } else {
                        dp[i][j].minval = min(dp[i][j - 1].minval * tmpv, dp[i - 1][j].minval * tmpv);
                        dp[i][j].maxval = max(dp[i][j - 1].maxval * tmpv, dp[i - 1][j].maxval * tmpv);
                    }
                } else if (tmpv < 0) {
                    if (i == 0 || j == 0) {
                        dp[i][j].minval = (i == 0 ? dp[i][j - 1] : dp[i - 1][j]).maxval * tmpv;
                        dp[i][j].maxval = (i == 0 ? dp[i][j - 1] : dp[i - 1][j]).minval * tmpv;
                    } else {
                        dp[i][j].minval = min(dp[i][j - 1].maxval * tmpv, dp[i - 1][j].maxval * tmpv);
                        dp[i][j].maxval = max(dp[i][j - 1].minval * tmpv, dp[i - 1][j].minval * tmpv);
                    }
                } else {
                    dp[i][j].minval = dp[i][j].maxval = 0;
                }
            }
        }
        if (dp[n - 1][m - 1].maxval < 0)
            return -1;
        else
            return (int)(dp[n - 1][m - 1].maxval % mod);
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> grid = {{1, -1, 0, -3, 4, 3, -3, 3, -1, 3, 0, 0, -4, 2}, {2, -2, -3, -4, 0, -2, -3, 3, 1, 4, 1, -3, -1, -4}, {-4, 4, -4, -4, 2, -4, 3, 0, -2, -4, 3, 4, -1, 0}, {-3, 3, -4, -4, 3, 4, 4, 1, -1, -1, 0, 3, 4, 1}, {1, 3, -4, 2, 2, -3, 1, -3, -4, -4, -1, -4, -4, 4}, {1, 1, -1, 1, -1, -1, 3, -4, -1, 2, -2, 3, -4, 0}, {1, 0, 3, 3, 1, 4, 1, 1, -4, -1, -3, 4, -4, 4}, {4, 3, 2, 3, 0, -1, 2, -4, 1, 0, 0, 1, 3, 4}, {-4, 4, -4, -4, 2, -2, 2, -1, 0, -2, 2, 4, -2, -1}, {-2, 3, 4, -4, 3, 3, -2, -1, 0, -3, 4, -2, -1, -4}, {4, 3, 3, 3, -3, 1, 2, -4, -1, 4, -3, -3, 2, 0}, {3, 3, 0, 1, -4, -4, -3, 3, -2, -4, 2, 4, -3, 3}, {-3, 0, 1, 3, 0, 0, 0, -4, -1, 4, -1, -3, 1, 1}, {-1, 4, 0, -3, 1, -3, -1, 2, 1, -3, -1, -4, 4, 1}};
    // grid = {
    //     {3, 5},
    //     {2, -1},
    //     {4, -4},
    // };
    cout << Solution().maxProductPath(grid) << endl;
    return 0;
}
