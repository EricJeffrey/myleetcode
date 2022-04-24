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

/*

maxp[i][j] 第j个位置在前i个时刻中的最大dp值
dp[i][j] 第i个时刻锤子在第j个位置，能打到的数目

dp[i][j] = max(dp[k][l], ... ) + 1 where t[i]-t[k] >= dis(l, j)

*/

class Solution {
public:
    int getMaximumNumber(vector<vector<int>> &moles) {
        typedef pair<int, int> pii;
        sort(moles.begin(), moles.end(), [](const vector<int> &v1, const vector<int> &v2) {
            return v1[0] < v2[0];
        });
        struct T {
            int t, index;
            vector<pii> poslist;
        };
        int index = 0;
        map<int, T> t2T;
        for (auto &&vec : moles) {
            int t = vec[0];
            if (t2T.find(t) == t2T.end()) {
                t2T[t] = {t, index, {}};
                index += 1;
            }
            t2T[t].poslist.push_back({vec[1], vec[2]});
        }
        size_t n = t2T.size();
        const int maxn = 1e5 + 5;
        int dp[maxn][3][3] = {};
        int dpmax[maxn][3][3] = {};
        T fir = t2T.begin()->second;
        for (auto &&p : fir.poslist) {
            if (fir.t == 0) {
                if (p.first == 1 && p.second == 1) {
                    dp[fir.index][p.first][p.second] = 1;
                    dpmax[fir.index][p.first][p.second] = 1;
                }
            } else {
                if (fir.t >= abs(p.first - 1) + abs(p.second - 1)) {
                    dp[fir.index][p.first][p.second] = 1;
                    dpmax[fir.index][p.first][p.second] = 1;
                }
            }
        }
        for (auto it = next(t2T.begin()); it != t2T.end(); it++) {
            fir = it->second;
            int i = fir.index, t = fir.t;
            bool has[3][3] = {};
            for (auto &&p : fir.poslist)
                has[p.first][p.second] = true;
            vector<int> indexList = {i - 1, -1, -1, -1, -1};
            for (int j = 1; j <= 4; j++) {
                auto tmpit = t2T.upper_bound(t - j);
                if (tmpit != t2T.end() && tmpit != t2T.begin()) {
                    --tmpit;
                    indexList[j] = tmpit->second.index;
                }
            }
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (!has[j][k]) {
                        dp[i][j][k] = max(dpmax[i - 1][j][k], dp[i][j][k]);
                        continue;
                    }
                    if (t >= abs(j - 1) + abs(k - 1))
                        dp[i][j][k] = max(dp[i][j][k], 1);
                    for (int jj = 0; jj < 3; jj++) {
                        for (int kk = 0; kk < 3; kk++) {
                            int dis = abs(jj - j) + abs(kk - k);
                            int tmpi = indexList[dis];
                            if (tmpi != -1)
                                dp[i][j][k] = max(dp[i][j][k], dpmax[tmpi][jj][kk] + 1);
                        }
                    }
                }
            }
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    dpmax[i][j][k] = max(dpmax[i][j][k], dp[i][j][k]);
                }
            }
        }
        int res = 0;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                res = max(dpmax[n - 1][j][k], res);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> moles;
    moles = {{1, 1, 0}, {2, 0, 1}, {4, 2, 2}};
    cout << Solution().getMaximumNumber(moles) << endl;
    moles = {{2, 0, 2}, {5, 2, 0}, {4, 1, 0}, {1, 2, 1}, {3, 0, 2}};
    cout << Solution().getMaximumNumber(moles) << endl;
    moles = {{0, 1, 0}, {0, 0, 1}};
    cout << Solution().getMaximumNumber(moles) << endl;
    return 0;
}
