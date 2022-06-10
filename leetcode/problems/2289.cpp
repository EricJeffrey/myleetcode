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

/*
[32 23 29 27, 24, 9, 14, 25, 19, 20 21, 22 23 17, 18, 15, 24, 29]
     1  2  1   1  1   2   3   1   2  3   4  5  1   2   1   6

0. 32 23 29 27, 24, 9, 14, 25, 19, 20 21, 22 23 17, 18, 15, 24, 29
1. 32 29 14 25 20 21 22 23 18 24 29
2. 32 25 21 22 23 24 29
3. 32 22 23 24 29
4. 32 23 24 29
5. 32 24 29
6. 32 29
7. 32
*/

class Solution {
public:
    int totalSteps(vector<int> &nums) {
        struct Tmp {
            int v, t;
        };
        stack<Tmp> s;
        s.push({nums[0], 0});
        int res = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            int v = nums[i];
            if (v < s.top().v) {
                s.push({v, 1});
                res = max(res, 1);
            } else if (v >= s.top().v) {
                int tmpMax = 0;
                while (!s.empty() && (v >= s.top().v || (s.top().t != 0 && tmpMax > s.top().t))) {
                    tmpMax = max(s.top().t + 1, tmpMax);
                    s.pop();
                }
                // 全递增
                if (s.empty())
                    s.push({v, 0});
                else {
                    s.push({v, tmpMax});
                    res = max(tmpMax, res);
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums;
    nums = {5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11};
    cout << Solution().totalSteps(nums) << endl;
    nums = {4, 5, 7, 7, 13};
    cout << Solution().totalSteps(nums) << endl;
    nums = {32, 23, 29, 27, 24, 9, 14, 25, 19, 20, 21, 22, 23, 17, 18, 15, 24, 29};
    cout << Solution().totalSteps(nums) << endl;
    return 0;
}
