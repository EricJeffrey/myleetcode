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
    int n, m;
    cin >> n >> m;
    vector<int> a1(m, 0), a2(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> a1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> a2[i];
    }
    set<string> s;
    for (int i = 0; i < m; i++) {
        s.insert(to_string(a1[i]) + "," + to_string(a2[i]));
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        string s1 = to_string(u) + "," + to_string(v);
        string s2 = to_string(v) + "," + to_string(u);
        if (s.find(s1) != s.end() || s.find(s2) != s.end())
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }

    return 0;
}
