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

// dp[i][j]
/*},
{{1,0,1,1,1,1},
{0,1,1,2,2,2},
{0,1,2,2,3,3},
{1,1,2,3,3,0},
{0,1,2,3,4,1}}

1 0 1 0 0
1 1 1 1 1
1 2 2 2 2
1 0 0 1 0
*/

class Solution {
  public:
    int maximalSquare(vector<vector<char>> &matrix) {
        const int n = matrix.size();
        if (n <= 0)
            return n;
        const int m = matrix[0].size();
        if (m <= 0)
            return 0;
        vector<vector<int>> dp(n);
        int res = 0;
        for (int i = 0; i < m; i++) {
            dp[0].push_back(matrix[0][i] - '0');
            res = max(res, dp[0][i]);
        }
        for (int i = 0; i < n; i++) {
            dp[i].push_back(matrix[i][0] - '0');
            res = max(res, dp[i][0]);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '0')
                    dp[i].push_back(0);
                else
                    dp[i].push_back(min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1);
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};
int main(int argc, char const *argv[]) {
    vector<vector<char>> matrix;
    matrix = {
        {1, 0, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 1, 1},
    };
    cout << Solution().maximalSquare(matrix) << endl;
    return 0;
}
