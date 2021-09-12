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
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<char> st;
        int res = 0;
        for (auto &&c : s) {
            if (st.empty()) {
                st.push(c);
                continue;
            }
            char topc = st.top();
            if (c == ']' && topc == '[' || c == '}' && topc == '{') {
                st.pop();
            } else if (c == '[' || c == '{') {
                st.push(c);
            } else {
                res++;
                st.pop();
            }
        }
        cout << res << endl;
    }
    return 0;
}
/*  */
