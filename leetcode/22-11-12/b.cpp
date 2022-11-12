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
    int countGoodStrings(int low, int high, int zero, int one) {
        const int maxn = 1e5 + 5;
        const int mod = 1e9 + 7;
        vector<long long> dp(maxn, 0);
        dp[zero] += 1;
        dp[one] += 1;
        long long res = 0;
        for (int i = 0; i <= high; i++) {
            if (i - zero >= 0) dp[i] += dp[i - zero];
            if (i - one >= 0) dp[i] += dp[i - one];
            dp[i] %= mod;
            if (i >= low) {
                res += dp[i];
                res %= mod;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().countGoodStrings(3, 3, 1, 1) << endl;
    cout << Solution().countGoodStrings(2, 3, 1, 2) << endl;
    cout << Solution().countGoodStrings(1, 100000, 1, 1) << endl;
    return 0;
}
