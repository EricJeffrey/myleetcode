#include <algorithm>
#include <array>
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
#include <vector>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int> &nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        int res = 0;
        for (int i = 0; i < (1 << len); i++) {
            int tmpRes = 0;
            for (int j = 0; j < len; j++) {
                if ((i & (1 << j)) != 0) {
                    tmpRes ^= nums[j];
                }
            }
            res += tmpRes;
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums;
    nums = {1, 3};
    cout << Solution().subsetXORSum(nums) << endl;
    nums = {5, 1, 6};
    cout << Solution().subsetXORSum(nums) << endl;
    nums = {3, 4, 5, 6, 7, 8};
    cout << Solution().subsetXORSum(nums) << endl;
    return 0;
}
