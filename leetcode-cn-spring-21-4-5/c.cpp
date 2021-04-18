
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    int magicTower(vector<int> &nums) {
        if (accumulate(nums.begin(), nums.end(), 0ll) + 1 <= 0)
            return -1;
        int res = 0;
        priority_queue<int> q;
        long long tmphp = 1;
        for (size_t i = 0; i < nums.size(); i++) {
            int u = nums[i];
            if (u < 0)
                q.push(-u);
            tmphp += u;
            if (tmphp <= 0) {
                while (tmphp <= 0 && !q.empty()) {
                    int tmp = q.top();
                    tmphp += tmp;
                    q.pop();
                    res += 1;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {-200, -300, 400, 0};
    nums = {100, 100, 100, -250, -60, -140, -50, -50, 100, 150};
    cout << Solution().magicTower(nums) << endl;
    return 0;
}