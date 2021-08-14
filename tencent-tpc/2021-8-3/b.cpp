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

const int maxn = 1e5;
vector<vector<long long>> table(maxn);

int main(int argc, char const *argv[]) {
    table[0] = {1};
    for (int i = 1; i < 100005; i++) {
        if (i >= 2000)
            table[i].resize(3);
        else
            table[i].resize(i + 1);
    }
    unordered_map<int, pair<int, int>> x2res;
    x2res[1] = {0, 0};
    for (int i = 1; i < maxn; i++) {
        for (int j = 0; j < table[i].size(); j++) {
            table[i][j] = 0;
            if (j - 1 >= 0)
                table[i][j] += table[i - 1][j - 1];
            if (j < table[i - 1].size())
                table[i][j] += table[i - 1][j];
            if (table[i][j] <= 1e9 && x2res.find(table[i][j]) == x2res.end()) {
                x2res[table[i][j]] = {i, j};
            }
        }
    }
    int t;
    // scanf("%d", &t);
    cin >> t;
    while (t--) {
        int x;
        // scanf("%d", &x);
        cin >> x;
        pair<int, int> res = {x, 1};
        if (x2res.find(x) != x2res.end())
            res = x2res[x];
        // printf("%d %d\n", res.first, res.second);
        cout << res.first << ' ' << res.second << endl;
    }

    return 0;
}
