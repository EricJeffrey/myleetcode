#include <algorithm>
#include <array>
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

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int32_t n, k;
        cin >> n >> k;
        std::vector<int> a(n + n, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i] = a[i + n] = x;
        }
        if (k == 1) {
            cout << 1 << ' ' << a[0] << endl;
            continue;
        }
        int which = -1, who;
        int last = a[0];
        int tmpcnt = 1;
        bool allsame = true;
        for (int i = 1; i < n + n; i++) {
            if (a[i] == last) {
                tmpcnt += 1;
                if (tmpcnt >= k) {
                    which = i + 1;
                    who = last;
                    break;
                }
            } else {
                allsame = false;
                last = a[i];
                tmpcnt = 1;
            }
        }
        if (allsame) {
            cout << k << ' ' << a[0] << endl;
        } else {
            if (which != -1) {
                cout << which << ' ' << who << endl;
            } else {
                cout << "INF" << endl;
            }
        }
    }

    return 0;
}
