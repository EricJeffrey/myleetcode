
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findUnsortedSubarray1(vector<int> &nums) {
        vector<int> nums_cp(nums);
        sort(nums.begin(), nums.end());
        const int sz = nums.size();
        int st = sz, ed = sz - 1;
        for (int i = 0; i < sz; i++) {
            if (nums[i] != nums_cp[i]) {
                st = i;
                break;
            }
        }
        for (int i = sz - 1; i >= 0; i--) {
            if (nums[i] != nums_cp[i]) {
                ed = i;
                break;
            }
        }
        return ed - st + 1;
    }
    int findUnsortedSubarray(vector<int> &nums) {
        const int sz = nums.size();
        int st = 0, ed = -1;
        int maxval = nums[0], minval = nums[sz - 1];
        for (int i = 1; i < sz; i++) {
            maxval = max(maxval, nums[i]);
            minval = min(minval, nums[sz - i - 1]);
            if (nums[i] < maxval)
                ed = i;
            if (nums[sz - i - 1] > minval)
                st = sz - i - 1;
        }
        return ed - st + 1;
    }
};

int main() {}
