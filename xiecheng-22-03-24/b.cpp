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

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> dp(s.size(), vector<int>(2, 0));
    dp[0][0] = (s[0] == '0' ? 0 : 1);
    dp[0][1] = (s[0] == '1' ? 0 : 1);
    for (int i = 1; i < s.size(); i++) {
        char ch = s[i] - '0';
        if (ch == 0) {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = i + 1 + dp[i - 1][0];
        } else {
            dp[i][0] = i + 1 + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0];
        }
    }
    cout << min(dp[s.size() - 1][0], dp[s.size() - 1][1]) << endl;
    return 0;
}
