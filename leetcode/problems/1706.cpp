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
    int dfs(int r, int c, const vector<vector<int>> &grid, vector<vector<int>> &mem) {
        if (r == grid.size())
            return c;
        if (mem[r][c] != -2)
            return mem[r][c];
        int res = -1;
        if (grid[r][c] == 1) {
            if (c + 1 < grid[0].size() && grid[r][c + 1] == 1) {
                res = dfs(r + 1, c + 1, grid, mem);
            }
        } else {
            if (c - 1 >= 0 && grid[r][c - 1] == -1)
                res = dfs(r + 1, c - 1, grid, mem);
        }
        mem[r][c] = res;
        return res;
    }
    vector<int> findBall(vector<vector<int>> &grid) {
        vector<vector<int>> mem(grid.size(), vector<int>(grid[0].size(), -2));
        vector<int> ans;
        for (size_t i = 0; i < grid[0].size(); i++) {
            ans.push_back(dfs(0, i, grid, mem));
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    //
    return 0;
}
