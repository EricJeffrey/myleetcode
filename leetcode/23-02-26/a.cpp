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
    vector<int> leftRigthDifference(vector<int> &nums) {
        if (nums.size() == 1) {
            return {0};
        }
        vector<int> prefix(nums.size(), 0);
        vector<int> suffix(nums.size(), 0);
        prefix[0] = nums[0];
        suffix.back() = nums.back();
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
        vector<int> ans(nums.size(), 0);
        ans[0] = abs(0 - suffix[1]);
        ans.back() = abs(prefix[nums.size() - 2] - 0);
        for (int i = 1; i < nums.size() - 1; i++){
            ans[i] = abs(prefix[i - 1] - suffix[i + 1]);
        }
        return ans;
    }
};