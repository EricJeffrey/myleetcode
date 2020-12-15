#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> dp;
    int numTrees(int n) {
        dp.resize(n + 3, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            int m = i - 1;
            for (int j = 0; j <= (m - 1) >> 1; j++) {
                dp[i] += dp[j] * dp[m - j] * 2;
            }
            if (i & 1)
                dp[i] += dp[m >> 1] * dp[m >> 1];
        }
        return dp[n];
    }
};

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    cout << Solution().numTrees(n) << endl;
    return 0;
}
