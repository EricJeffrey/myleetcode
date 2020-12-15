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
    int maxProduct(vector<int> &nums) {
        // 2, 0, -5, 8, -4, 3, -2, 4
        const int n = nums.size();
        if (n <= 0)
            return 0;
        typedef pair<int, int> PII;
        PII cur, la;
        la = nums[0] > 0 ? PII(nums[0], 0) : PII(0, nums[0]);
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            const int v = nums[i];
            if (v > 0)
                cur = PII(max(v, v * la.first), min(0, la.second * v));
            else
                cur = PII(max(0, la.second * v), min(v, v * la.first));
            res = max(res, cur.first);
            la = cur;
        }
        return res;
    }
};
int main(int argc, char const *argv[]) { return 0; }
