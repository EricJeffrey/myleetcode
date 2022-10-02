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
    int deleteString(string s) {
        vector<int> dp(s.size(), 1);
        auto isSame = [&s](int a, int b) {
            for (int i = 0; i < b - a; i++) {
                if (b + i >= s.size()) return false;
                if (s[a + i] != s[b + i]) return false;
            }
            return true;
        };
        set<pair<int, int>> poses[26];
        for (int i = s.size() - 1; i >= 0; i--) {
            int what = s[i] - 'a';
            int tmpres = 1;
            for (auto it = poses[what].rbegin(); it != poses[what].rend(); it++) {
                int nextpos = it->second;
                if (isSame(i, nextpos)) {
                    tmpres = max(tmpres, it->first + 1);
                    break;
                }
            }
            dp[i] = tmpres;
            poses[what].insert({dp[i], i});
        }
        return dp[0];
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().deleteString("abcabcdabc") << endl;
    cout << Solution().deleteString("aaabaab") << endl;
    cout << Solution().deleteString("aaaaa") << endl;
    return 0;
}
