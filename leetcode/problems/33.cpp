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
    int search(vector<int> &nums, int target) {
        const int n = nums.size();
        if (n <= 0)
            return -1;
        else if (n == 1)
            return (nums[0] == target ? 0 : -1);
        else if (n == 2)
            return (nums[0] == target ? 0 : nums[1] == target ? 1 : -1);
        int pos = findRotatePos(nums);
        if (pos == 1)
            return nums[0] == target ? 0 : bs(nums, 1, n, target);
        else if (pos == n - 1)
            return nums[n - 1] == target ? n - 1 : bs(nums, 0, pos, target);
        else if (pos == n)
            return bs(nums, 0, n, target);
        int res = bs(nums, 0, pos, target);
        return res == -1 ? bs(nums, pos, n, target) : res;
    }
    int findRotatePos(vector<int> &nums) {
        const int n = nums.size();
        if (nums[0] > nums[1])
            return 1;
        else if (nums[n - 1] < nums[n - 2])
            return n - 1;
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[0])
                r = mid;
            else if (nums[mid] > nums[0])
                l = mid + 1;
        }
        return l;
    }
    int bs(vector<int> &nums, int l, int r, int target) {
        const int n = r;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > target)
                r = mid;
            else if (nums[mid] == target)
                return mid;
            else
                l = mid + 1;
        }
        return (l != n && nums[l] == target ? l : -1);
    }
};
int main(int argc, char const *argv[]) {
    // 0 1 2 3 4 5 6 7
    // 4,5,6,7,0,1,2
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    while (cin >> target) {
        cout << Solution().search(nums, target) << endl;
    }
    return 0;
}
