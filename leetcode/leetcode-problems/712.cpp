#include <algorithm>
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
#include <vector>
using namespace std;

/*
delete
leet
*/

vector<vector<int>> mem;
class Solution1 {
public:
    vector<vector<int>> occurs{26};

    int dfs(const string &s1, const string &s2, int pos1, int pos2) {
        if (pos1 >= s1.size() || pos2 >= s2.size())
            return 0;
        if (mem[pos1][pos2] != -1)
            return mem[pos1][pos2];
        const char ch = s2[pos2];
        auto it = lower_bound(occurs[ch - 'a'].begin(), occurs[ch - 'a'].end(), pos1);
        int res = 0;
        if (it != occurs[ch - 'a'].end())
            res = max(res, ch + dfs(s1, s2, (*it) + 1, pos2 + 1));
        res = max(res, dfs(s1, s2, pos1, pos2 + 1));
        return mem[pos1][pos2] = res;
    }

    int minimumDeleteSum(string s1, string s2) {
        if (s1.size() < s2.size())
            s1.swap(s2);
        mem.clear();
        mem.resize(s1.size(), vector<int>(s2.size(), -1));
        for (auto &occ : occurs) occ.clear();
        int totalAscSum = 0;
        for (auto &&ch : s1) totalAscSum += ch;
        for (auto &&ch : s2) totalAscSum += ch;
        for (size_t i = 0; i < s1.size(); i++)
            occurs[s1[i] - 'a'].push_back(i);
        int res = dfs(s1, s2, 0, 0);
        return totalAscSum - 2 * res;
    }
};
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        for (int i = s1.size() - 1; i >= 0; i--)
            dp[i][s2.size()] = s1[i] + dp[i + 1][s2.size()];
        for (int i = s2.size() - 1; i >= 0; i--)
            dp[s1.size()][i] = s2[i] + dp[s1.size()][i + 1];

        for (int i = s1.size() - 1; i >= 0; i--) {
            for (int j = s2.size() - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    dp[i][j] = dp[i + 1][j + 1];
                else
                    dp[i][j] = min(dp[i + 1][j] + s1[i], dp[i][j + 1] + s2[j]);
            }
        }
        return dp[0][0];
    }
};

int main(int argc, char const *argv[]) {
    (*((Solution *)nullptr)).minimumDeleteSum("aab", "ccda");
    return 0;
}
