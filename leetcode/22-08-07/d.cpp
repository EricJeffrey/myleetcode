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

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        int res = 0;
        for (size_t i = 0; i < s.size(); i++) {
            char ch = s[i];
            int tmpMax = 0;
            for (int t = -k; t <= k; t++) {
                int nc = ch + t;
                if (nc < 'a' || nc > 'z')
                    continue;
                tmpMax = max(tmpMax, dp[nc - 'a'] + 1);
            }
            dp[ch - 'a'] = max(dp[ch - 'a'], tmpMax);
            // cout << "DEBUG:" << dp[ch - 'a'] << endl;
            res = max(res, dp[ch - 'a']);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().longestIdealString("abcd", 4) << endl;
    cout << Solution().longestIdealString("slddedwfmo", 16) << endl;
    cout << Solution().longestIdealString("aaaa", 16) << endl;
    return 0;
}
