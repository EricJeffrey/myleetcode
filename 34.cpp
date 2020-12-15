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

// first pos such that nums[pos] >= target
int lb(vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] < target)
            l = mid + 1;
        if (nums[mid] >= target)
            r = mid;
    }
    return l;
}
// first pos such that nums[pos] > target
int ub(vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] <= target)
            l = mid + 1;
        if (nums[mid] > target)
            r = mid;
    }
    return l;
}

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        const int n = nums.size();
        int l = lb(nums, target), r = ub(nums, target) - 1;
        if (l < 0 || l >= n || nums[l] != target)
            return {-1, -1};
        return {l, r};
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums = {5, 7, 8, 8, 8, 10}, res;
    int target = 6;
    res = Solution().searchRange(nums, target);
    cout << res[0] << ", " << res[1] << endl;
    return 0;
}
