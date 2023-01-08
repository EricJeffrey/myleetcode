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
    long long maxKelements(vector<int> &nums, int k) {
        multiset<int, greater<int>> s;
        for (auto &&v : nums) {
            s.insert(v);
        }
        long long res = 0;
        for (int i = 0; i < k; i++) {
            auto it = s.begin();
            res += *it;
            int nv = ceil(1.0 * (*it) / 3);
            s.erase(it);
            s.insert(nv);
        }
        return res;
    }
};