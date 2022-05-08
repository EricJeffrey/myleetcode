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
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();
        if (n <= 0)
            return 0;
        unordered_map<char, int> mp;
        vector<int> dp(n, 1);
        int res = 1;
        mp[s[0]] = 0;
        for (int i = 1; i < n; i++) {
            const char v = s[i];
            if (mp.find(v) != mp.end()) {
                int pos = mp[v];
                dp[i] = (i - 1 - dp[i - 1] < pos) ? i - pos : dp[i - 1] + 1;
            } else {
                dp[i] = dp[i - 1] + 1;
            }
            mp[v] = i;
            res = max(res, dp[i]);
        }
        return res;
    }
};