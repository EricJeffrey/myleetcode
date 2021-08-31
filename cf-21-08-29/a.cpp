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
        int c, d;
        cin >> c >> d;
        int res = 0;
        if (c == d) {
            res = (c == 0 ? 0 : 1);
        } else if (abs(c - d) % 2 == 0) {
            res = 2;
        } else {
            res = -1;
        }
        cout << res << endl;
    }
    return 0;
}
