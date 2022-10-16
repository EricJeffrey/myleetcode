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
    int countDistinctIntegers(vector<int> &nums) {
        set<int64_t> s;
        for (auto &&v : nums) {
            s.insert(v);
        }
        for (auto &&v : nums) {
            string tmp = to_string(v);
            reverse(tmp.begin(), tmp.end());
            s.insert(stoll(tmp));
        }
        return s.size();
    }
};