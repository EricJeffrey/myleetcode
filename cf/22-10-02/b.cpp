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
    //
    int t;
    cin >> t;
    int a[100] = {};
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int target = 2 * a[0] - 1;
        int res = 0;
        for (int i = 1; i < n; i++) {
            int u = a[i];
            if (u % target == 0)
                res += u / target - 1;
            else
                res += u / target;
        }
        cout << res << endl;
    }
    return 0;
}
