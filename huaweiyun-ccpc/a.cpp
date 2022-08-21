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
dp[n][m] 0~n分成m段的最小和

    dp[i][j] = min(dp[i - k][j - 1] + calc95(i-k+1, i)), k=1...n, i-k >= j-1

2
5 2
777 96 114 920 206
5 5
804 253 746 267 487

 */

int calc(int start, int end, const vector<int> &nums) {
    vector<int> tmp{nums.begin() + start, nums.begin() + end + 1};
    sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - (int)floor(0.05 * tmp.size()) - 1];
}

int work(int n, int m, const vector<int> &nums) {
    vector<vector<int>> dp(n, vector<int>(m + 1, INT32_MAX));
    for (int i = 0; i < n; i++) {
        dp[i][1] = calc(0, i, nums);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 2; j <= i + 1 && j <= m; j++) {
            for (int k = 1; i - k + 1 >= j - 1; k++) {
                int tmp = calc(i - k + 1, i, nums);
                dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + tmp);
            }
        }
    }
    return dp[n - 1][m];
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << work(n, m, nums) << endl;
    }
    return 0;
}
