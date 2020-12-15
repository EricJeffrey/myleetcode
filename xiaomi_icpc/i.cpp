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

const int maxn = 1003;

int main(int argc, char const *argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<string> matrix(n);
    for (int i = 0; i < n; i++) {
        char buf[maxn] = {};
        scanf("%s", buf);
        matrix[i] = string(buf);
    }
    struct point {
        int x, y;
    };
    queue<point> q;
    auto check = [&n, &m](int x, int y, char ch) {
        if (ch == 'S' && x == n - 1) return true;
        if (ch == 'W' && x == 0) return true;
        if (ch == 'A' && y == 0) return true;
        if (ch == 'D' && y == m - 1) return true;
        return false;
    };
    vector<vector<int>> ok(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check(i, j, matrix[i][j])) {
                q.push({i, j});
                ok[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        point u = q.front();
        q.pop();
        int vx = u.x, vy = u.y;
        vx = u.x - 1, vy = u.y;
        if (vx >= 0 && vx < n && vy >= 0 && vy < m && !ok[vx][vy] && matrix[vx][vy] == 'S') {
            q.push({vx, vy});
            ok[vx][vy] = true;
        }
        vx = u.x + 1, vy = u.y;
        if (vx >= 0 && vx < n && vy >= 0 && vy < m && !ok[vx][vy] && matrix[vx][vy] == 'W') {
            q.push({vx, vy});
            ok[vx][vy] = true;
        }
        vx = u.x, vy = u.y - 1;
        if (vx >= 0 && vx < n && vy >= 0 && vy < m && !ok[vx][vy] && matrix[vx][vy] == 'D') {
            q.push({vx, vy});
            ok[vx][vy] = true;
        }
        vx = u.x, vy = u.y + 1;
        if (vx >= 0 && vx < n && vy >= 0 && vy < m && !ok[vx][vy] && matrix[vx][vy] == 'A') {
            q.push({vx, vy});
            ok[vx][vy] = true;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ok[i][j]) res++;
        }
    }
    printf("%d\n", res);

    return 0;
}