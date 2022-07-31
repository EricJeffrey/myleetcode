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
#include <vector>
using namespace std;

int work(int r1, int c1, int r2, int c2) {
    struct Tmp {
        int r, c, step;
    };
    auto isonpath = [r2, c2](int r, int c, int which) {
        switch (which) {
        case 0:
            return (r == r2 && c - 1 == r2) || (r - 1 == r2 && c - 2 == c2);
        case 1:
            return (r == r2 && c - 1 == r2) || (r + 1 == r2 && c - 2 == c2);
        case 2:
            return (r + 1 == r2 && c == c2) || (r + 2 == r2 && c - 1 == c2);
        case 3:
            return (r + 1 == r2 && c == c2) || (r + 2 == r2 && c + 1 == c2);
        case 4:
            return (r == r2 && c + 1 == c2) || (r + 1 == r2 && c + 2 == c2);
        case 5:
            return (r == r2 && c + 1 == c2) || (r - 1 == r2 && c + 2 == c2);
        case 6:
            return (r - 1 == r2 && c == c2) || (r - 2 == r2 && c + 1 == c2);
        case 7:
            return (r - 1 == r2 && c == c2) || (r - 2 == r2 && c - 1 == c2);
        default:
            break;
        }
        return false;
    };
    int res = -1;
    queue<Tmp> q;
    q.push({r1, c1, 0});
    vector<vector<bool>> visit(10, vector<bool>(9, false));
    while (!q.empty()) {
        Tmp u = q.front();
        q.pop();
        if (u.r == r2 && u.c == c2) {
            res = u.step;
        }
        if (visit[u.r][u.c])
            continue;
        visit[u.r][u.c] = true;
        int nrs[8] = {u.r - 2, u.r + 2, u.r + 3, u.r + 3, u.r + 2, u.r - 2, u.r - 3, u.r - 3};
        int ncs[8] = {u.c - 3, u.c - 3, u.c - 2, u.c + 2, u.c + 3, u.c + 3, u.c + 2, u.c - 2};
        for (int i = 0; i < 8; i++) {
            int nr = nrs[i], nc = ncs[i];
            if (nr >= 0 && nr < 10 && nc >= 0 && nc < 9 && !visit[nr][nc] &&
                !isonpath(u.r, u.c, i)) {
                q.push({nr, nc, u.step + 1});
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[]) {
    int r1, c1;
    int r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << work(r1, c1, r2, c2) << endl;
    // int cnt = 0;
    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 9; j++) {
    //         for (int k = 0; k < 10; k++) {
    //             for (int l = 0; l < 9; l++) {
    //                 int res = work(i, j, k, l);
    //                 cout << cnt++ << ':'<< res << endl;
    //                 if (res < 0) {
    //                     cout << "ERROR:" << i << j << k << l << endl;
    //                     return 0;
    //                 }
    //             }
    //         }
    //     }
    // }

    return 0;
}
