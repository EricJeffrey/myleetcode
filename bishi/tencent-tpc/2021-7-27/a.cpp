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
        int n, k;
        cin >> n >> k;
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        a[0] += b[0];
        int cnts[205] = {};
        for (int i = 0; i < n; i++) {
            cnts[a[i]]++;
        }
        int rank = 1;
        int tenrank = -1;
        for (int i = 200; i >= 0; i--) {
            if (i == a[0]) {
                tenrank = rank;
                break;
            }
            rank += cnts[i];
        }
        if (tenrank <= k)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
