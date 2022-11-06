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
    long long maximumSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long res = 0;
        long long tmpSum = 0;
        for (int i = 0; i < k; i++) {
            if (mp.find(nums[i]) == mp.end()) mp[nums[i]] = 0;
            mp[nums[i]] += 1;
            tmpSum += nums[i];
        }
        if (mp.size() == k) res = tmpSum;
        for (int i = 1; i < n && i + k - 1 < n; i++) {
            int u = nums[i - 1], v = nums[i + k - 1];
            if (mp.find(v) == mp.end()) mp[v] = 0;
            mp[v] += 1;
            mp[u] -= 1;
            if (mp[u] == 0) mp.erase(u);
            tmpSum -= u;
            tmpSum += v;
            if (mp.size() == k) res = max(res, tmpSum);
        }
        return res;
    }
};
