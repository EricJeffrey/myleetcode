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
    int minNumBooths(vector<string> &demand) {
        bool hasletter[26] = {};
        for (auto &&s : demand) {
            for (auto &&ch : s) {
                hasletter[ch - 'a'] = true;
            }
        }
        int maxcnt[26] = {};
        for (auto &&s : demand) {
            int tmpcnt[26] = {};
            for (auto &&ch : s) {
                tmpcnt[ch - 'a'] += 1;
            }
            for (int i = 0; i < 26; i++) {
                maxcnt[i] = max(maxcnt[i], tmpcnt[i]);
            }
        }
        int res = 0;
        for (auto &&v : maxcnt) {
            res += v;
        }
        return res;
    }
};
