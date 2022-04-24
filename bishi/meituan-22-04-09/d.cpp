
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
1,2 1,3 2,3   3*2=6
3*2 = 6 * 2

c(n,2)+n*(n-1)*(n-2)*2+c(n,4)
 */

int main(int argc, char const *argv[]) {
    const int mod = 1e9 + 7;
    long long prod[11] = {1, 1};
    for (int i = 2; i < 11; i++) {
        prod[i] = i * prod[i - 1];
        prod[i] %= mod;
    }
    int n;
    cin >> n;
    if (n <= 1) {
        cout << 0 << endl;
        return 0;
    }
    long long res = 0;
    res += 2 * prod[n] / (2 * prod[n - 2]);
    res %= mod;
    res += n * (n - 1) * (n - 2) * 2;
    res %= mod;
    if (n >= 4)
        res += n * (n - 1) * (n - 2) * (n - 3);
    res %= mod;
    cout << res << endl;
    return 0;
}
