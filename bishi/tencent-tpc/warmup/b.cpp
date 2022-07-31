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
        int n;
        cin >> n;
        vector<int> a;
        int numof[1001] = {};
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
            numof[x]++;
        }
        bool ok = true;
        vector<int> vof2;
        for (int i = 0; i < 1001; i++) {
            if (numof[i] >= 3) {
                ok = false;
                break;
            }
            if (numof[i] == 2) {
                vof2.push_back(i);
            }
        }
        if (!ok || vof2.size() > 1) {
            cout << 0 << endl;
            continue;
        }
        auto check = [&](int target) {
            for (int i = 1; i <= (target - 1) / 2; i++) {
                if (numof[i] > 0 || numof[target - i] > 0) {
                    continue;
                } else {
                    return true;
                }
            }
            return false;
        };
        if (!vof2.empty()) {
            if (check(vof2[0]))
                cout << 2 << endl;
            else
                cout << 0 << endl;
        } else {
            int res = 0;
            for (int i = 0; i < n; i++) {
                if (check(a[i]))
                    res++;
            }
            cout << res << endl;
        }
    }

    return 0;
}
