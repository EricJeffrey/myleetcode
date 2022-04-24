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

int dfs(int row, int col, int n, int m, int tmpcost, vector<vector<int>> costs, vector<vector<bool>> visited, vector<vector<int>> matrix) {
    if (row < 0 || col < 0 || row >= n || col >= m || matrix[row][col] == 2)
        return INT32_MAX;
    if (visited[row][col])
        return INT32_MAX;
    tmpcost += (matrix[row][col] == 0 ? 2 : 1);
    if (row == n - 1 && col == m - 1) {
        if (costs[n - 1][m - 1] > tmpcost)
            costs[n - 1][m - 1] = tmpcost;
        return costs[n - 1][m - 1];
    }
    if (costs[row][col] <= tmpcost)
        return costs[row][col];
    visited[row][col] = true;
    vector<int> tmpreslist;

    tmpreslist.push_back(dfs(row + 1, col, n, m, tmpcost, costs, visited, matrix));
    tmpreslist.push_back(dfs(row, col + 1, n, m, tmpcost, costs, visited, matrix));
    tmpreslist.push_back(dfs(row - 1, col, n, m, tmpcost, costs, visited, matrix));
    tmpreslist.push_back(dfs(row, col - 1, n, m, tmpcost, costs, visited, matrix));
    visited[row][col] = false;
    return costs[row][col] = *min_element(tmpreslist.begin(), tmpreslist.end());
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算最小航行费用
     * @param input int整型vector<vector<>> 二维网格
     * @return int整型
     */
    int minSailCost(vector<vector<int>> &input) {
        // write code here
        if (input.size() == 0 || input[0].size() == 0 || input[0][0] == 2)
            return -1;
        int n = input.size();
        int m = input[0].size();
        vector<vector<int>> costs(n, vector<int>(m, INT32_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int res = dfs(0, 0, n, m, 0, costs, visited, input);
        if (res == INT32_MAX)
            return -1;
        return res - (input[0][0] == 0 ? 2 : 1);
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> input;
    input = {{1, 1, 1, 1, 0}, {0, 1, 0, 1, 0}, {1, 1, 2, 1, 1}, {0, 2, 0, 0, 1}};
    cout << Solution().minSailCost(input) << endl;
    return 0;
}
