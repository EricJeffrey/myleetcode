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

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    if (j > 0)
                        prefix[i][j] = prefix[i][j - 1] + 1;
                    else
                        prefix[i][j] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0')
                    continue;
                int minpre = prefix[i][j];
                int tmp = minpre;
                for (int k = i + 1; k < n; k++) {
                    if (matrix[k][j] == '0')
                        break;
                    minpre = min(minpre, prefix[k][j]);
                    tmp = max(tmp, minpre * (k - i + 1));
                }
                res = max(tmp, res);
            }
        }

        return res;
    }
};
int main(int argc, char const *argv[]) {
    vector<vector<char>> matrix;
    matrix = {
        {'0', '1', '0', '1', '1', '0', '0'},
        {'0', '0', '1', '1', '0', '0', '1'},
        {'0', '0', '1', '0', '0', '0', '0'},
        {'1', '0', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '0', '0', '0', '0'},
        {'0', '1', '1', '0', '1', '1', '0'},
        {'1', '1', '0', '1', '0', '1', '1'},
    };
    cout << Solution().maximalRectangle(matrix) << endl;
    return 0;
}

/*


0  1  0  1  1  0  0
0  0  1  1  0  0  1
1  0  1  1  1  1  1
0  1  1  0  1  1  0
1  1  1  0  1  1  1
1  1  0  1  1  1  1
0  0  1  0  0  1  0

0  1  0  1  2  0  0
0  0  1  2  0  0  1
1  0  1  2  3  4  5
0  1  2  0  1  2  0
1  2  3  0  1  2  3
1  2  0  1  2  3  4
0  0  1  0  0  1  0


*/