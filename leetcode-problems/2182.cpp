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

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int cnts[26] = {};
        for (auto &&ch : s) {
            cnts[ch - 'a'] += 1;
        }
        deque<pair<char, int>> q;
        for (int i = 26 - 1; i >= 0; i--) {
            if (cnts[i] != 0) {
                q.push_back(make_pair('a' + i, cnts[i]));
            }
        }
        string res;
        while (q.empty() == false) {
            auto u = q.front();
            q.pop_front();
            for (int i = 0; i < min(repeatLimit, u.second); i++) {
                res += u.first;
            }
            if (u.second > repeatLimit) {
                if (q.empty() == false) {
                    auto v = q.front();
                    q.pop_front();
                    res += v.first;
                    v.second -= 1;
                    if (v.second > 0)
                        q.push_front(v);
                    u.second -= repeatLimit;
                    q.push_front(u);
                } else {
                    break;
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().repeatLimitedString("aababab", 2) << endl;
    return 0;
}
