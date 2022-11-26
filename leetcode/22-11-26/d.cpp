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
    int countPalindromes(string s) {
        /*
        cnts[i][j] = 第i个字符及之后，字符 j 的个数
        dp[i][j][k] = 第i个字符及之后，子序列 jk 的个数
            dp[i][j][k] = dp[i + 1][j][k] + (s[i] == 'j' ? cnts[i + 1][k])
        suffix[i][j][k] = 第i个字符及之后，可选的
        */
        int n = s.size();
        if (n < 5) {
            return 0;
        }
        const int mod = 1e9 + 7;
        vector<vector<vector<long long>>> dp(
            s.size(), vector<vector<long long>>(10, vector<long long>(10, 0)));
        {
            vector<vector<int>> cnts(n, vector<int>(10, 0));
            for (int i = n - 1; i >= 0; i--) {
                if (i != n - 1) cnts[i] = cnts[i + 1];
                cnts[i][s[i] - '0'] += 1;
            }
            dp[n - 2][s[n - 2] - '0'][s[n - 1] - '0'] = 1;
            for (int i = n - 3; i >= 0; i--) {
                int c = s[i] - '0';
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 10; k++) {
                        dp[i][j][k] = dp[i + 1][j][k];
                        if (c == j) dp[i][j][k] += cnts[i + 1][k];
                    }
                }
            }
        }
        vector<vector<vector<long long>>> rdp(
            s.size(), vector<vector<long long>>(10, vector<long long>(10, 0)));
        {
            vector<vector<int>> cnts(n, vector<int>(10, 0));
            for (int i = 0; i < n; i++) {
                if (i != 0) cnts[i] = cnts[i - 1];
                cnts[i][s[i] - '0'] += 1;
            }
            rdp[1][s[0] - '0'][s[1] - '0'] = 1;
            for (int i = 2; i < n; i++) {
                int c = s[i] - '0';
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 10; k++) {
                        rdp[i][j][k] = rdp[i - 1][j][k];
                        if (c == k) rdp[i][j][k] += cnts[i - 1][j];
                    }
                }
            }
        }
        long long res = 0;
        for (int i = 2; i <= n - 3; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    long long tmp = dp[i + 1][j][k] * rdp[i - 1][k][j];
                    tmp %= mod;
                    res += tmp;
                    res %= mod;
                }
            }
        }
        return (int)(res % mod);
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().countPalindromes("000000") << endl;
    cout << Solution().countPalindromes("230740587") << endl;
    return 0;
}

