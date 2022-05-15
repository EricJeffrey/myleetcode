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
    int largestCombination(vector<int> &candidates) {
        const int maxn = 32;
        int sums[maxn] = {};
        for (auto &&v : candidates) {
            int i = 0;
            while (v != 0) {
                if (v & 1)
                    sums[i] += 1;
                v >>= 1;
                i += 1;
            }
        }
        return *max_element(sums, sums + maxn);
    }
};