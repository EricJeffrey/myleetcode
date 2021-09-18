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

int main(int argc, char const *argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> res(n, vector<int>(m, 0));
    vector<int> withleft(n * m + 1);
    vector<int> withup(n * m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int id;
            int x, y, z, w;
            scanf("%d %d %d %d %d", &id, &x, &y, &z, &w);
            withleft[x] = id;
            withup[y] = id;
            if (x == 0 && y == 0)
                res[0][0] = id;
        }
    }
    auto findupisv = [&withup](int v) {
        return withup[v];
    };
    auto findleftisv = [&withleft](int v) {
        return withleft[v];
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                continue;
            if (j == 0) {
                int v = res[i - 1][j];
                res[i][j] = findupisv(v);
            } else {
                int v = res[i][j - 1];
                res[i][j] = findleftisv(v);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    /* 
3 3
1 2 4 8 6
2 0 5 1 7
3 4 0 0 8
4 5 0 3 1
5 0 0 4 2
6 7 1 9 0
7 0 2 6 0
8 1 3 0 9
9 6 8 0 0
*/

    return 0;
}
