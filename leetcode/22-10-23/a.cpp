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
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        auto vtoi = [](const string &s) {
            return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
        };
        int s1 = vtoi(event1[0]), e1 = vtoi(event1[1]);
        int s2 = vtoi(event2[0]), e2 = vtoi(event2[1]);
        if (e1 < s2 || s1 > e2) return false;
        return true;
    }
};