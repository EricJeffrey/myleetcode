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
    int minSwaps(vector<int> &nums) {
        int cntof1 = 0;
        for (auto &&v : nums) {
            if (v == 1)
                cntof1++;
        }
        vector<int> target(nums.size(), 0);
        for (size_t i = 0; i < cntof1; i++) {
            target[i] = 1;
        }
        int minswap = 0;
        int tmpswap = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != target[i])
                tmpswap += 1;
        }
        minswap = tmpswap / 2;
        for (size_t i = cntof1; i < nums.size(); i++) {
            if (nums[i] != target[i])
                tmpswap -= 1;
            else
                tmpswap += 1;
            if (nums[i - cntof1] != target[i - cntof1])
                tmpswap -= 1;
            else
                tmpswap += 1;
            target[i] = 1, target[i - cntof1] = 0;
            minswap = min(minswap, tmpswap / 2);
        }
        tmpswap = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            target[i] = i < cntof1 ? 1 : 0;
            if (nums[i] != target[i])
                tmpswap += 1;
        }
        for (int i = cntof1 - 1, j = 1; i >= 0; i--, j++) {
            if (nums[i] != target[i])
                tmpswap -= 1;
            else
                tmpswap += 1;
            if (nums[nums.size() - j] != target[nums.size() - j])
                tmpswap -= 1;
            else
                tmpswap += 1;
            target[i] = 0, target[nums.size() - j] = 1;
            minswap = min(minswap, tmpswap / 2);
        }
        return minswap;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums;
    nums = {0, 1, 0, 1, 1, 0, 0};
    cout << Solution().minSwaps(nums) << endl;
    nums = {0, 1, 1, 1, 0, 0, 1, 1, 0};
    cout << Solution().minSwaps(nums) << endl;
    nums = {1, 1, 1, 1, 0, 0, 0, 1};
    cout << Solution().minSwaps(nums) << endl;
    return 0;
}
