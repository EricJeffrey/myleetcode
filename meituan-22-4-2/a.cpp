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
    int n, pr, pb;
    cin >> n >> pb >> pr;
    string s;
    cin >> s;
    if (n < 2) {
        cout << n << endl;
        return 0;
    }
    int rc = 0, bc = 0;
    int first = 0, second = 1;
    while (second < s.size()) {
        if (s[first] == s[second]) {
            if (s[first] == 'r') {
                bc++;
            } else {
                rc++;
            }
        }
        first++;
        second++;
    }
    if (rc <= pr && bc <= pb) {
        cout << rc + bc + n << endl;
    } else {
        cout << max(0, bc - pb) << ' ' << max(0, rc - pr) << endl;
    }
    return 0;
}
