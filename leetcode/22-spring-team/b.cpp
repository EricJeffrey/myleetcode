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
    int conveyorBelt(vector<string> &matrix, vector<int> &start, vector<int> &end) {
        typedef pair<int, int> pii;
        typedef pair<int, pii> pipii;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        pii s = {start[0], start[1]};
        pii e = {end[0], end[1]};

        int res = abs(s.first - e.first) + abs(s.second - e.second);
        vector<vector<int>> dp(n, vector<int>(m, n * m));
        priority_queue<pipii, vector<pipii>, greater<pipii>> q;
        q.push({0, e});
        while (!q.empty()) {
            auto u = q.top();
            q.pop();
            auto cnt = u.first;
            auto pos = u.second;
            if (visited[pos.first][pos.second])
                continue;
            visited[pos.first][pos.second] = true;
            if (pos == s) {
                res = min(res, cnt);
                continue;
            }
            auto push = [&matrix, &q, cnt, &visited](pii next, char c) {
                if (visited[next.first][next.second])
                    return;
                if (matrix[next.first][next.second] == c)
                    q.push({cnt, next});
                else
                    q.push({cnt + 1, next});
            };
            if (pos.first >= 1) {
                push({pos.first - 1, pos.second}, 'v');
            }
            if (pos.first <= n - 2) {
                push({pos.first + 1, pos.second}, '^');
            }
            if (pos.second >= 1) {
                push({pos.first, pos.second - 1}, '>');
            }
            if (pos.second <= m - 2) {
                push({pos.first, pos.second + 1}, '<');
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<string> matrix;
    vector<int> start, end;
    matrix = {">>v", "v^<", "<><"};
    start = {0, 1};
    end = {2, 0};
    cout << Solution().conveyorBelt(matrix, start, end) << endl;
    matrix = {">>v", ">>v", "^<<"};
    start = {0, 0};
    end = {1, 1};
    cout << Solution().conveyorBelt(matrix, start, end) << endl;
    matrix = {">^^>", "<^v>", "^v^<"};
    start = {0, 0};
    end = {1, 3};
    cout << Solution().conveyorBelt(matrix, start, end) << endl;
    return 0;
}
