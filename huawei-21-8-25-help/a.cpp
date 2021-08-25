#include <cstdio>
#include <vector>
using namespace std;

int calc(int i, int j, int k, int l, vector<vector<int>> &nums) {
    int res = 0;
    for (int ni = i; ni <= k; ni++) {
        for (int nj = j; nj <= l; nj++) {
            res += nums[ni][nj];
        }
    }
    return res;
}
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
    int maxres = -1001 * 100;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    if (k == i && l == j)
                        continue;
                    int tmpres = calc(i, j, k, l, nums);
                    maxres = max(maxres, calc(i, j, k, l, nums));
                }
            }
        }
    }
    printf("%d\n", maxres);

    return 0;
}
