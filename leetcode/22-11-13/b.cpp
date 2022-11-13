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
    int subarrayLCM(vector<int> &nums, int k) {
        int res = 0;
        auto lcm = [](long long a, long long b) { return a * b / __gcd(a, b); };
        for (size_t i = 0; i < nums.size(); i++) {
            long long lastLcm = nums[i];
            if (lastLcm == k)
                res++;
            else if (lastLcm > k)
                continue;
            for (size_t j = i + 1; j < nums.size(); j++) {
                long long tmplcm = lcm(lastLcm, nums[j]);
                if (tmplcm == k) {
                    res += 1;
                }
                if (tmplcm > k) break;
                lastLcm = tmplcm;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums;
    int k;
    nums = {2, 1, 1, 5};
    k = 5;
    cout << Solution().subarrayLCM(nums, k) << endl;
    return 0;
}
