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
    bool hasAlpha(const string &s) {
        for (auto &&v : s) {
            if (isalpha(v)) return true;
        }
        return false;
    }
    int maximumValue(vector<string> &strs) {
        vector<int64_t> values;
        for (auto &&v : strs) {
            if (hasAlpha(v)) {
                values.push_back(v.size());
            } else {
                values.push_back(stoll(v));
            }
        }
        return *max_element(values.begin(), values.end());
    }
};
