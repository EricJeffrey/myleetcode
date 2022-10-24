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
    long long minCost(vector<int> &nums, vector<int> &cost) {
        auto costOnX = [&cost, &nums](int x) {
            int64_t res = 0;
            for (size_t i = 0; i < nums.size(); i++) {
                int64_t u = nums[i];
                res += abs(u - x) * cost[i];
            }
            return res;
        };
        /*
        4 5 9
        c1 c2 c3 4 5 9
        6 -> 8 5 27
        7 -> 12 10 18
        8 -> 16 15 9
        如果相等必然是拐点所以不需考虑
        */
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = (l + r) >> 1;
            int64_t leftVal = costOnX(mid - 1);
            int64_t midVal = costOnX(mid);
            int64_t rightVal = costOnX(mid + 1);
            if (leftVal >= midVal && rightVal >= midVal) {
                return midVal;
            }
            if (leftVal == midVal || rightVal == midVal) {
                return midVal;
            }
            if (leftVal < midVal && midVal < rightVal) {
                r = mid - 1;
            }
            if (leftVal > midVal && midVal > rightVal) {
                l = mid + 1;
            }
        }
        return costOnX(l);
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums, costs;
    nums = {1, 3, 5, 2}, costs = {2, 3, 1, 14};
    // for (int i = -3; i <= 8; i++) {
    //     int tmp = 0;
    //     for (size_t j = 0; j < nums.size(); j++) {
    //         tmp += abs(nums[j] - i) * costs[j];
    //     }
    //     cout << tmp << ",";
    // }
    cout << Solution().minCost(nums, costs) << endl;
    nums = {2, 2, 2, 2, 2}, costs = {4, 2, 8, 1, 3};
    cout << Solution().minCost(nums, costs) << endl;
    nums = {1, 2}, costs = {1, 100};
    cout << Solution().minCost(nums, costs) << endl;
    return 0;
}
