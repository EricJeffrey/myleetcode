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
#include <unordered_set>
#include <vector>
using namespace std;

// 过了 76%
int main(int argc, char const *argv[]) {
    int n, Q;
    cin >> n >> Q;
    while (Q--) {
        string s;
        cin >> s;
        auto check = [](string s) {
            for (size_t i = 1; i < s.size(); i++)
                if (s[i] < s[i - 1])
                    return false;
            return true;
        };
        unordered_set<string> soccured;
        queue<pair<string, int>> q;
        q.push({s, 0});
        soccured.insert(s);
        int res = 0;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            if (check(u.first)) {
                res = u.second;
                break;
            }
            for (int i = 1; i <= n; i++) {
                string ns = u.first;
                reverse(ns.begin(), ns.begin() + i);
                if (soccured.find(ns) == soccured.end()) {
                    q.push({ns, u.second + 1});
                    soccured.insert(ns);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
