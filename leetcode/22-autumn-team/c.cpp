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
    int beautifulBouquet(vector<int> &flowers, int cnt) {
        const int maxn = 1e5 + 1;
        const int mod = 1e9 + 7;
        vector<vector<int>> poses(maxn);
        vector<long long> dp(flowers.size(), 0);
        dp[0] = 1;
        poses[flowers[0]].push_back(0);
        int curmaxpos = -1;
        for (size_t i = 1; i < flowers.size(); i++) {
            int u = flowers[i];
            dp[i] = dp[i - 1];
            int tmp = 0;
            // cout << "DEBUG, amx: " << curmaxpos << endl;
            if (poses[u].size() + 1 <= cnt) {
                tmp = i - curmaxpos;
            } else {
                curmaxpos = max(curmaxpos, poses[u][poses[u].size() - cnt]);
                tmp = i - curmaxpos;
            }
            dp[i] = (dp[i] + tmp) % mod;
            // cout << "DEBUG: " << dp[i] << endl;
            poses[u].push_back(i);
        }
        return dp.back();
    }
};

int main(int argc, char const *argv[]) {
    vector<int> flowers;
    int cnt;
    flowers = {5, 3, 3, 3, 3}, cnt = 2;
    cout << Solution().beautifulBouquet(flowers, cnt) << endl;
    flowers = {5, 3, 3, 3}, cnt = 2;
    cout << Solution().beautifulBouquet(flowers, cnt) << endl;
    flowers = {83395, 48132, 48132, 48132, 48132, 48132, 10442, 48132}, cnt = 1;
    cout << Solution().beautifulBouquet(flowers, cnt) << endl;
    flowers = {5, 3, 3, 3, 3, 3, 2, 3}, cnt = 2;
    cout << Solution().beautifulBouquet(flowers, cnt) << endl;
    return 0;
}
