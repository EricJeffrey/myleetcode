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
    int maxProfit(vector<int> &prices) {
        const int n = prices.size();
        if (n <= 0)
            return 0;
        int dp[2][3] = {}, x = 0;
        dp[0][2] = -prices[0];
        for (int i = 2; i <= n; i++) {
            x = !x;
            int pi = i - 1;
            dp[x][0] = max(dp[!x][0], dp[!x][1]);
            dp[x][1] = dp[!x][2] + prices[pi];
            dp[x][2] = max(dp[!x][0] - prices[pi], dp[!x][2]);
        }
        int res = 0;
        for (int i = 0; i < 3; i++)
            res = max(res, dp[x][i]);
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}
