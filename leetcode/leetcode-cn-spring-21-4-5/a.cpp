#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int purchasePlans(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        int mod = 1e9 + 7;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int u = nums[i];
            int v = target - u;
            if (v > 0) {
                int x = upper_bound(nums.begin(), nums.begin() + i, v) - nums.begin();
                cout << x << endl;
                res += x;
                res %= mod;
            }
        }

        return static_cast<int>(res);
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums = {2, 5, 3, 5};
    nums = {2, 2, 1, 9};
    cout << Solution().purchasePlans(nums, 10) << endl;
    return 0;
}
