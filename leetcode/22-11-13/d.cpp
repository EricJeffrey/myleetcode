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
    int maxPalindromes(string s, int k) {
        if (k == 1) return s.size();
        vector<int> posOfChar[26];
        for (int i = 0; i < s.size(); i++) {
            posOfChar[s[i] - 'a'].push_back(i);
        }
        vector<int> dp(s.size(), 0);
        auto isPalindrome = [&s](int pos, int i) {
            while (pos < i && s[pos] == s[i]) {
                pos++, i--;
            }
            return pos >= i;
        };
        for (int i = 1; i < s.size(); i++) {
            dp[i] = dp[i - 1];
            for (auto &&pos : posOfChar[s[i] - 'a']) {
                if ((i - pos + 1) < k || pos >= i) {
                    break;
                }
                if (isPalindrome(pos, i)) {
                    if (pos - 1 >= 0)
                        dp[i] = max(dp[i], 1 + dp[pos - 1]);
                    else
                        dp[i] = max(dp[i], 1);
                }
            }
        }
        return dp.back();
    }
};

int main(int argc, char const *argv[]) {
    string s;
    int k;
    s = "abaccdbbd", k = 3;
    cout << Solution().maxPalindromes(s, k) << endl;
    s = "adbcda", k = 2;
    cout << Solution().maxPalindromes(s, k) << endl;
    return 0;
}
