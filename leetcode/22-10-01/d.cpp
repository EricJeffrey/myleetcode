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
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff) {
        const int maxn = 6e4 + 5;
        vector<int> tree(maxn, 0);
        auto lowbit = [](int x) { return x & (-x); };
        auto addtree = [&tree, &lowbit](int which, int value) {
            which += 3e4 + 1;
            while (which < tree.size()) {
                tree[which] += value;
                which += lowbit(which);
            }
        };
        auto getSum = [&tree, &lowbit](int x){
            x += 3e4 + 1;
            int res = 0;
            while (x > 0) {
                res += tree[x];
                x -= lowbit(x);
            }
            return res;
        };

        for (size_t i = 0; i < nums1.size(); i++) {
            int u = nums1[i], v = nums2[i];
            addtree(u - v + diff, 1);
        }

        long long res = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int u = nums1[i], v = nums2[i];
            addtree(u - v + diff, -1);
            res += getSum(3e4) -  getSum(u - v - 1);
        }
        return res;
    }
};