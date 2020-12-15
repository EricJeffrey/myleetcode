#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
  private:
    int dp[2][2003] = {};

  public:
    int findTargetSumWays(vector<int> &nums, int S) {
        if (nums.size() <= 0 || S > 1000)
            return 0;
        // dp[i][j] = dp[i][j - x] + dp[i][j + x]
        bool x = 0;
        int tmp = nums[0];
        if (tmp == 0)
            dp[x][1001] = 2;
        else
            dp[x][tmp + 1001] = dp[x][-tmp + 1001] = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            x = !x;
            tmp = nums[i];
            memset(dp[x], 0, sizeof(int) * 2003);
            for (int j = 0; j < 2002; j++) {
                if (j - tmp >= 0)
                    dp[x][j] += dp[!x][j - tmp];
                if (j + tmp < 2002)
                    dp[x][j] += dp[!x][j + tmp];
            }
            // log
            // cout << "---------------------log---------------------" << endl;
            // cout << i + 1 << ":";
            // for(int j = 1002; j < 1007; j++)
            //     cout << dp[x][j] << ' ';
            // cout << endl << "---------------------end---------------------"
            // << endl;
        }
        return dp[x][S + 1001];
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums = {1, 999};
    cout << Solution().findTargetSumWays(nums, 998) << endl;
    return 0;
}
