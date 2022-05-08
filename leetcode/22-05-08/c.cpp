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

/*
2 1
22 2
222 1+2+1 4
2222 4+2+1 7
22222 7+4+2

 */

const int mod = 1e9 + 7;
class Solution {
    vector<unordered_map<int, int>> mem;
    int dfs(int n, int m) {
        if (m <= 0)
            return 0;
        if (m == 1)
            return 1;
        if (m == 2)
            return 2;
        if (m == 3)
            return 4;
        if ((n == 7 || n == 9) && m == 4)
            return 8;
        if (mem[n].find(m) != mem[n].end())
            return mem[n][m];
        if ((n == 7 || n == 9)) {
            long long tmp = 0;
            tmp = (tmp + dfs(n, m - 1)) % mod;
            tmp = (tmp + dfs(n, m - 2)) % mod;
            tmp = (tmp + dfs(n, m - 3)) % mod;
            tmp = (tmp + dfs(n, m - 4)) % mod;
            mem[n][m] = (int)tmp;
            return int(tmp);
        } else {
            long long tmp = 0;
            tmp = (tmp + dfs(n, m - 1)) % mod;
            tmp = (tmp + dfs(n, m - 2)) % mod;
            tmp = (tmp + dfs(n, m - 3)) % mod;
            mem[n][m] = (int)tmp;
            return int(tmp);
        }
    }

public:
    int countTexts(string pressedKeys) {
        if (mem.empty())
            mem.resize(1e5 + 1);
        long long res = 1;
        char last = pressedKeys[0];
        size_t lasti = 0;
        for (size_t i = 1; i < pressedKeys.size(); i++) {
            if (pressedKeys[i] != last) {
                int tmp = dfs(last - '0', i - lasti);
                res = res * tmp;
                res %= mod;
                last = pressedKeys[i];
                lasti = i;
            }
        }
        res = res * dfs(last - '0', pressedKeys.size() - lasti);
        res = res % mod;
        return int(res);
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().countTexts("22233") << endl;
    cout << Solution().countTexts("222222222222222222222222222222222222") << endl;
    cout << Solution().countTexts("7") << endl;
    cout << Solution().countTexts("77777777799999") << endl;
    cout << Solution().countTexts("88888888888888888888888877777777777777777777777788888888888888888888888855555555555555555555555533333333333333333333333322222222222222222222222277777777777777777777777766666666666666666666666677777777777777777777777777777777777777777777777744444444444444444444444444444444444444444444444466666666666666666666666644444444444444444444444477777777777777777777777766666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666644444444444444444444444444444444444446666666666666666666666662222222222222229999999999999999999999995555555222222222255444444466666") << endl;
    return 0;
}
