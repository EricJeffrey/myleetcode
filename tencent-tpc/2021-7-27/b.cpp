#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> f(n + 1, vector<int>(0));
        queue<int> q;
        vector<int> tt(n + 1, 0);

        for (int i = 0; i < k; i++) {
            int m;
            cin >> m;
            int pre = 0;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                if (j > 0) {
                    f[pre].push_back(x);
                } else {
                    tt[x]++;
                    if (tt[x] == 2) {
                        q.push(x);
                    }
                }
                pre = x;
            }
        }
        int res = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (f[x].size() > 0) {
                int y = f[x][0];
                tt[y]++;
                if (tt[y] == 2) {
                    q.push(y);
                }
            }
            if (f[x].size() > 1) {
                int y = f[x][1];
                tt[y]++;
                if (tt[y] == 2) {
                    q.push(y);
                }
            }

            res = 1 - res;
        }

        if (res == 0)
            cout << "Nacho" << endl;
        else
            cout << "Kelly" << endl;
    }

    return 0;
}