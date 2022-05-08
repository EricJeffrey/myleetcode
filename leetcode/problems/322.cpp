#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        if (coins.size() <= 0)
            return -1;
        if (amount == 0)
            return 0;
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        int ed = distance(coins.begin(), unique(coins.begin(), coins.end()));
        for (int i = 0; i < ed; i++) {
            const int ci = coins[i];
            if (ci > amount)
                break;
            for (int j = ci; j <= amount; j++) {
                if (dp[j - ci] != -1) {
                    if (dp[j] == -1)
                        dp[j] = dp[j - ci] + 1;
                    else
                        dp[j] = min(dp[j], dp[j - ci] + 1);
                }
            }
        }
        return dp[amount];
    }
};
/*
dp[i]
*/
int main(int argc, char const *argv[]) { return 0; }
