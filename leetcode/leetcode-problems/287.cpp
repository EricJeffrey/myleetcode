#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        if (nums.size() <= 0)
            return 0;
        int fast = nums[nums[0]], slow = nums[0];
        while (fast != slow) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        fast = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> vec = {3, 1, 2, 4, 2};
    cout << Solution().findDuplicate(vec) << endl;
    return 0;
}
