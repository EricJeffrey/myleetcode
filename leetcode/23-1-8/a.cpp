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
    int maximumCount(vector<int> &nums) {
        int pos, neg;
        pos = neg = 0;
        for (auto &&v : nums) {
            if (v > 0) pos++;
            if (v < 0) neg++;
        }
        return max(pos, neg);
    }
};
