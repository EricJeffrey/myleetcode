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
    bool hasValidPath(vector<vector<char>> &grid) {
        typedef pair<int, int> pii;
        typedef set<int> seti;

        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        vector<vector<seti>> gs(m, vector<seti>(n));
        vector<vector<int>> gcnt(m, vector<int>(n, 0));

        auto update1 = [&gs, &gcnt, &grid](int r, int c, const seti &t) {
            gcnt[r][c] += 1;
            if (r == 0 || c == 0)
                gcnt[r][c] = 2;
            for (auto &&v : t) {
                int tmp = v + (grid[r][c] == '(' ? 1 : -1);
                if (tmp >= 0)
                    gs[r][c].insert(tmp);
            }
        };

        queue<pii> q;
        q.push({0, 0});
        gs[0][0].insert(1);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            if (u.first == m - 1 && u.second == n - 1) {
                if (gs[u.first][u.second].count(0) != 0)
                    return true;
                else
                    return false;
            }
            if (u.first + 1 < m) {
                pii next = u;
                next.first += 1;
                update1(next.first, next.second, gs[u.first][u.second]);
                if (gcnt[next.first][next.second] == 2)
                    q.push(next);
            }
            if (u.second + 1 < n) {
                pii next = u;
                next.second += 1;
                update1(next.first, next.second, gs[u.first][u.second]);
                if (gcnt[next.first][next.second] == 2)
                    q.push(next);
            }
        }
        return false;
    }
};