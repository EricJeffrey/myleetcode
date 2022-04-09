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
    int n;
    cin >> n;
    vector<int> c1(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> c1[i];
    }
    int m;
    cin >> m;
    vector<int> c2(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> c2[i];
    }
    int maxlen = 0;
    for (int i = 0; i < m; i++) {
        int len = 0;
        int i1 = 0, i2 = i;
        while (i1 < n && i2 < m) {
            if (c1[i1] == c2[i2]) {
                len += 1;
                i1++;
                i2++;
            } else
                break;
        }
        if (i2 == m)
            maxlen = max(maxlen, len);
    }
    int res = n + m;
    res = min(res, n - maxlen + m - maxlen);
    cout << res << endl;
    return 0;
}
