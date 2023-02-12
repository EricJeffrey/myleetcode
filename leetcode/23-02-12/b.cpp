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
    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        vector<int> nnums = nums;
        sort(nnums.begin(), nnums.end());
        long long res = 0;
        for (auto &&v : nums) {
            int a = lower - v;
            int b = upper - v;
            auto it1 = lower_bound(nnums.begin(), nnums.end(), a);
            auto it2 = upper_bound(nnums.begin(), nnums.end(), b);
            int tmp = distance(it1, it2);
            if (v >= a && v <= b) {
                tmp -= 1;
            }
            res += tmp;
        }
        return res / 2;
    }
};