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
#include <vector>
using namespace std;

class Solution {
  public:
    void sortColors(vector<int> &nums) {
        const int n = nums.size();
        int i = 0, opos = 0, twopos = n - 1;
        for (int i = 0; i < n; i++) {
            while (nums[i] == 2 && i < twopos)
                swap(nums[i], nums[twopos--]);
            while (nums[i] == 0 && i > opos)
                swap(nums[i], nums[opos++]);
        }
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums;
    nums = {0, 1, 2, 0, 2, 1, 1, 2, 0, 1, 0, 2, 1, 2, 1, 0, 2};
    Solution().sortColors(nums);
    for (int v : nums) {
        cout << v << ' ';
    }

    return 0;
}
