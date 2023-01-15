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
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries) {
        vector<vector<int>> prefixs(n, vector<int>(n + 2, 0));
        for (auto &&query : queries) {
            int row1i, col1i, row2i, col2i;
            row1i = query[0], col1i = query[1];
            row2i = query[2], col2i = query[3];
            for (int i = row1i; i <= row2i; i++) {
                prefixs[i][col1i + 1] += 1;
                prefixs[i][col2i + 2] -= 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n; j++) {
                prefixs[i][j] += prefixs[i][j - 1];
            }
        }
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = prefixs[i][j + 1];
            }
        }
        return res;
    }
};