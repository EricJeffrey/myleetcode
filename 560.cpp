#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
    int subarraySum(vector<int> &nums, int k) {
        const int n = nums.size();
        if (n == 1)
            return nums[0] == k;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefix = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            res += mp[prefix - k];
            mp[prefix]++;
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums;
    nums = {4, 3, 9, -2, 6, 4, -3, 10, -8, 4, 1};
    // nums = {-1, -1, 1};
    int k = 7;
    cout << Solution().subarraySum(nums, k) << endl;
    return 0;
}
