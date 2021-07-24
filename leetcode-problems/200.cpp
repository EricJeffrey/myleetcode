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
#include <vector>
using namespace std;
class Solution {
  private:
    int m, n;

  public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.size() <= 0)
            return 0;
        int res = 0;
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(i, j, grid);
                }
            }
        }
        return res;
    }
    void dfs(int i, int j, vector<vector<char>> &g) {
        if (i < 0 || i >= m || j < 0 || j >= n || g[i][j] == '0')
            return;
        g[i][j] = '0';
        dfs(i + 1, j, g);
        dfs(i, j + 1, g);
        dfs(i - 1, j, g);
        dfs(i, j - 1, g);
    }
};
int main(int argc, char const *argv[]) { return 0; }
