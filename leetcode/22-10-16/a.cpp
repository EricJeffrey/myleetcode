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
    int findMaxK(vector<int> &nums) {
        set<int> s(nums.begin(), nums.end());
        int res = -1;
        for (auto &&v : nums) {
            if (v > 0 && s.find(-v) != s.end()) {
                res = max(v, res);
            }
        }
        return res;
    }
};