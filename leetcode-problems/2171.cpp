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
    long long minimumRemoval(vector<int> &beans) {
        sort(beans.begin(), beans.end());
        size_t n = beans.size();
        vector<long long> prefix(n, 0), suffix(n, 0);
        prefix[0] = beans[0];
        suffix[n - 1] = beans[n - 1];
        for (size_t i = 1; i < beans.size(); i++) {
            prefix[i] = prefix[i - 1] + beans[i];
        }
        for (int i = beans.size() - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + beans[i];
        }
        long long res = INT64_MAX;
        for (size_t i = 0; i < n; i++) {
            long long tmppref = (i == 0 ? 0 : prefix[i - 1]);
            long long tmpsuf = (i == n - 1 ? 0 : suffix[i + 1]);
            res = min(res, tmppref + (tmpsuf - (long long)(n - i - 1) * beans[i]));
        }
        return res;
    }
};