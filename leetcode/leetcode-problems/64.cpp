#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.size() <= 0)
            return 0;
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m);
        dp[0] = grid[0][0];
        for (int i = 1; i < m; i++)
            dp[i] = grid[0][i] + dp[i - 1];
        for (int i = 1; i < n; i++) {
            dp[0] = dp[0] + grid[i][0];
            for (int j = 1; j < m; j++) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1];
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> vec = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << Solution().minPathSum(vec) << endl;
    return 0;
}
