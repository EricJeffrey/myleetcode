#include <algorithm>
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

struct State {
    int maxSquareSize, value;
};

class Solution {

public:
    int countSquares(vector<vector<int>> &matrix) {
        const size_t rowSize = matrix.size(), colSize = matrix[0].size();
        vector<vector<State>> dp(rowSize, vector<State>(colSize));
        dp[0][0] = {matrix[0][0], matrix[0][0]};
        for (size_t i = 1; i < rowSize; i++) dp[i][0] = {matrix[i][0], matrix[i][0] + dp[i - 1][0].value};
        for (size_t j = 1; j < colSize; j++) dp[0][j] = {matrix[0][j], matrix[0][j] + dp[0][j - 1].value};
        for (size_t i = 1; i < rowSize; i++) {
            for (size_t j = 1; j < colSize; j++) {
                int tmpRes = dp[i - 1][j].value + dp[i][j - 1].value - dp[i - 1][j - 1].value;
                if (matrix[i][j] == 1) {
                    int maxSquareSize = 1 + min(dp[i - 1][j].maxSquareSize, min(dp[i][j - 1].maxSquareSize, dp[i - 1][j - 1].maxSquareSize));
                    dp[i][j] = {maxSquareSize, tmpRes + maxSquareSize};
                } else {
                    dp[i][j] = {0, tmpRes};
                }
            }
        }
        return dp[rowSize - 1][colSize - 1].value;
    }
};
int main(int argc, char const *argv[]) {
    auto testout = [](vector<vector<int>> m, int v) {
        cout << "result: " << Solution().countSquares(m) << ", should be: " << v << endl;
    };
    testout({
                {0, 1, 1, 1},
                {1, 1, 1, 1},
                {0, 1, 1, 1},
            },
            15);
    testout({
                {1, 0, 1},
                {1, 1, 0},
                {1, 1, 0},
            },
            7);
    testout({
                {1, 1},
                {1, 1},
            },
            5);
    testout({
                {1, 1, 1},
                {1, 1, 1},
                {1, 1, 1},
            },
            14);
    testout({
                {1, 1, 1, 1},
                {0, 1, 1, 1},
            },
            9);
    testout({
                {1, 1, 1},
                {1, 1, 1},
            },
            8);
    return 0;
}
