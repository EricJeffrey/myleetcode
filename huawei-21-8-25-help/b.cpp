#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct Tmp {
    int r, c;
    int step;
};
int main(int argc, char const *argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> nums(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            scanf(" %d", &x);
            nums[i][j] = x;
        }
    }
    if (nums[n - 1][m - 1] == 0 || nums[0][0] == 0) {
        printf("-1\n");
        return 0;
    }
    int res = -1;
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    queue<Tmp> q;
    q.push({0, 0, 0});
    while (!q.empty()) {
        Tmp u = q.front();
        q.pop();
        if (u.r == n - 1 && u.c == m - 1) {
            if (nums[n - 1][m - 1] - u.step == 0)
                continue;
            else {
                res = u.step;
                break;
            }
        }
        visit[u.r][u.c] = 1;
        int nstep = u.step + 1;
        vector<pair<int, int>> tmpcr = {{u.r + 1, u.c}, {u.r - 1, u.c}, {u.r, u.c + 1}, {u.r, u.c - 1}};
        for (auto &&pv : tmpcr) {
            int nr = pv.first, nc = pv.second;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visit[nr][nc] && nums[nr][nc] - nstep >= 0) {
                q.push({nr, nc, nstep});
            }
        }
    }
    printf("%d\n", res);

    return 0;
}

/* 

5 5
3 5 4 2 3
4 5 3 4 3
4 3 5 3 2
2 5 3 3 5
5 3 4 4 3

3 3
2 3 2
5 1 1
4 5 5




*/