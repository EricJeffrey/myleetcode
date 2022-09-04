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
    bool checkDistances(string s, vector<int> &distance) {
        vector<pair<int, int>> poslist;
        poslist.resize(26, {-1, -1});
        for (size_t i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (poslist[c].first == -1)
                poslist[c].first = i;
            else
                poslist[c].second = i;
        }
        bool ok = true;
        for (auto &&ch : s) {
            int c = ch - 'a';
            if (distance[c] != poslist[c].second - poslist[c].first - 1) {
                ok = false;
                break;
            }
        }
        return ok;
    }
};