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
    vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
        auto findMax = [&](int r, int c) {
            int res = grid[r][c];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    res = max(res, grid[r - i][c - j]);
                }
            }
            return res;
        };
        vector<vector<int>> res(grid.size() - 2);
        for (size_t i = 2; i < grid.size(); i++) {
            for (size_t j = 2; j < grid[0].size(); j++) {
                res[i - 2].push_back(findMax(i, j));
            }
        }
        return res;
    }
};