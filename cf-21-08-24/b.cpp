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

/*

alice-0, bob-1

0 1 0
1 0 1

1 0 1 0 1
0 1 0 1 0

1 1 1 1 0



0 1 0 1 0 1
1 0 1 0 1 0

0 0 1 1 1 1


0:a, 1:b


even:
    n / 2 --> xb
    base = n - xb
    x = min(a, b), y = max(a, b)
        all-x-on-pos: y-base
        (x-1)-on-pos: 1+(y-(base-1))
        (x-t)-on-pos: t+(y-(base-t))=2t+y-base

odd:
    xb = n/2
    base = n - xb
    x = min(a, b), y = max(a, b)
        (x-t)-on-pos: t+(y-(base-t))=2t+y-base

    xb = n / 2 + 1
    base = n - xb
        (x-t)-on-pos: t+(y-(base-t))=2t+y-base


 */

int main(int argc, char const *argv[]) {
    //
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int x = min(a, b), y = max(a, b);
        int n = a + b;
        int xbase = n / 2;
        int base = n - xbase;
        set<int> s;
        for (int i = 0; i <= x; i++) {
            s.insert(2 * i + y - base);
        }
        if (n % 2 == 1) {
            base = n - xbase - 1;
            for (int i = 0; i <= x; i++) {
                s.insert(2 * i + y - base);
            }
        }
        cout << s.size() << endl;
        for (auto &&v : s) {
            cout << v << ' ';
        }
        cout << endl;
    }
    return 0;
}
