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
    string optimalDivision(vector<int> &nums) {
        if (nums.size() == 1) {
            return to_string(nums[0]);
        }
        const size_t n = nums.size();
        vector<vector<double>> vals(n, vector<double>(n, 1));
        for (size_t i = 0; i < n; i++) {
            vals[i][i] = nums[i];
            double last = nums[i];
            for (size_t j = i + 1; j < n; j++) {
                last = last / nums[j];
                vals[i][j] = last;
            }
        }
        typedef pair<double, vector<int>> T;
        vector<T> dpmin(n + 1);
        vector<T> dpmax(n + 1);
        dpmin[n - 1] = dpmax[n - 1] = {nums[n - 1], {}};
        dpmin[n - 2] = dpmax[n - 2] = {nums[n - 2] * 1.0 / nums[n - 1], {}};
        for (int i = n - 3; i >= 0; i--) {
            T minval = {vals[i][n - 1], {}};
            T maxval = {vals[i][n - 1], {}};
            int minwhich = -1;
            int maxwhich = -1;
            for (int j = i; j < n - 2; j++) {
                double tmpmin = vals[i][j] / dpmax[j + 1].first;
                if (tmpmin < minval.first) {
                    minwhich = j + 1;
                    minval = {tmpmin, dpmax[j + 1].second};
                }
                double tmpmax = vals[i][j] / dpmin[j + 1].first;
                if (tmpmax > maxval.first) {
                    maxwhich = j + 1;
                    maxval = {tmpmax, dpmin[j + 1].second};
                }
            }
            if (minwhich != -1)
                minval.second.push_back(minwhich);
            if (maxwhich != -1)
                maxval.second.push_back(maxwhich);
            dpmin[i] = minval;
            dpmax[i] = maxval;
        }
        set<size_t> pos(dpmax[0].second.begin(), dpmax[0].second.end());
        string res = to_string(nums[0]);
        int cnt = 0;
        for (size_t i = 1; i < n; i++) {
            res += '/';
            if (pos.find(i) != pos.end()) {
                res += '(';
                cnt += 1;
            }
            res += to_string(nums[i]);
        }
        while (cnt > 0) {
            res += ')';
            cnt -= 1;
        }
        return res;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> nums;
    nums = {2, 3, 4};
    cout << Solution().optimalDivision(nums) << endl;
    nums = {1000, 100, 10, 2};
    cout << Solution().optimalDivision(nums) << endl;
    nums = {2, 3};
    cout << Solution().optimalDivision(nums) << endl;
    nums = {2};
    cout << Solution().optimalDivision(nums) << endl;
    nums = {311, 324, 608, 625, 445, 168, 86, 549, 668, 166};
    cout << Solution().optimalDivision(nums) << endl;
    return 0;
}
