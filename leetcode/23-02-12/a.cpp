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
    long long findTheArrayConcVal(vector<int>& nums) {
        long long res = 0;
        int i, j;
        for (i = 0, j = nums.size() - 1; i < j; i++, j--) {
            res += stoll(to_string(nums[i]) + to_string(nums[j]));
        }
        if (i == j) res += nums[i];
        return res;
    }
};