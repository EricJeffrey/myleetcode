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
    int longestDecomposition(string text) {
        /*
        dp[i][j] 从下标为i开始，i处长度为j的回文段长度
        dp[i][j] = 2 + max(dp[i+j])

        0 1 2 3 4 5 6
      7 a b c d e f g
      6 a b c d e f

         */
        vector<set<int>> graph;
        int n = text.size();
        graph.resize(n / 2 + 1);
        for (int i = 0; i <= n / 2; i++) {
            for (int j = 1; j + i - 1 < n / 2; j++) {
                auto le = text.substr(i, j);
                auto ri = text.substr(n - i - j, j);
                if (le == ri)
                    graph[i].insert(j);
            }
        }
        // cout << "-----DEBUG-----" << endl;
        // for (int i = 0; i <= n / 2; i++) {
        //     cout << i << ": ";
        //     for (int j : graph[i]) {
        //         cout << j << ',';
        //     }
        //     cout << endl;
        // }
        // cout << "-----DEBUG-----" << endl;
        int dp[1001] = {};
        for (int i = 0; i < (n + 1) / 2; i++) {
            dp[i] = 1;
        }
        for (int i = n / 2 - 1; i >= 0; i--) {
            for (int j : graph[i]) {
                dp[i] = max(dp[i], dp[i + j] + 2);
            }
        }
        return dp[0];
    }
};

int main(int argc, char const *argv[]) {
    auto s = Solution();
    cout << s.longestDecomposition("merchant") << endl;
    cout << s.longestDecomposition("ghiabcdefhelloadamhelloabcdefghi") << endl;
    cout << s.longestDecomposition("antaprezatepzapreanta") << endl;
    cout << s.longestDecomposition("sskd dbk sdkkfkk dbk dfd dd dd dfd dbk sdkkfkk dbk sskd") << endl;
    return 0;
}
