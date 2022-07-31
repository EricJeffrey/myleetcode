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
    pair<int, bool> dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited) {
        if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1)
            return make_pair(0, true);
        if (grid[i][j] == 0 || visited[i][j])
            return make_pair(0, false);
        visited[i][j] = true;

        pair<int, bool> res = make_pair(1, false);
        pair<int, bool> tmp;
        tmp = dfs(grid, i + 1, j, visited);
        res.first += tmp.first, res.second |= tmp.second;
        tmp = dfs(grid, i - 1, j, visited);
        res.first += tmp.first, res.second |= tmp.second;
        tmp = dfs(grid, i, j + 1, visited);
        res.first += tmp.first, res.second |= tmp.second;
        tmp = dfs(grid, i, j - 1, visited);
        res.first += tmp.first, res.second |= tmp.second;
        return res;
    }
    int numEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j])
                    continue;
                if (grid[i][j] == 1) {
                    auto tmp = dfs(grid, i, j, visited);
                    if (tmp.second == false)
                        res += tmp.first;
                }
            }
        }
        return res;
    }
};
