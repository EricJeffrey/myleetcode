#include <algorithm>
#include <array>
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
class Solution {
public:
    int reductionOperations(vector<int> &nums) {
        const int maxn = 5e4 + 5;
        int count[maxn] = {};
        for (auto &&v : nums) {
            count[v] += 1;
        }
        vector<int> vs;
        for (int i = maxn - 1; i >= 0; i--) {
            if (count[i] > 0)
                vs.push_back(count[i]);
        }
        for (int i = 1; i < vs.size() - 1; i++) {
            vs[i] += vs[i - 1];
        }
        int res = 0;
        for (int i = 0; i < vs.size() - 1; i++) {
            res += vs[i];
        }
        return res;
    }
};