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
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k) {
        int m = modulo;
        vector<int> indexs;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % m == k) {
                indexs.push_back(i);
            }
        }
        vector<int> lcnts, rcnts;
        for (int i = 0; i < indexs.size(); i++) {
            int idx = indexs[i];
            lcnts.push_back((i == 0 ? idx : idx - indexs[i - 1] - 1));
            rcnts.push_back(
                (i == indexs.size() - 1 ? nums.size() - 1 - idx : indexs[i + 1] - idx - 1));
        }
        if (false) {
            for (int i = 0; i < indexs.size(); i++) {
                cout << indexs[i] << ": " << lcnts[i] << ", " << rcnts[i] << endl;
            }
        }
        long long res = 0;
        if (k == 0) {
            for (int i = 0; i < indexs.size(); i++) {
                res += (1ll + lcnts[i]) * lcnts[i] / 2;
            }
            if (!rcnts.empty()) {
                res += (1ll + rcnts.back()) * rcnts.back() / 2;
            }
        }
        for (int i = 0; i < indexs.size(); i++) {
            for (int j = k == 0 ? m : k; (i + j - 1) < indexs.size(); j += m) {
                if (j == 0) {
                    continue;
                }
                long long lc = lcnts[i] + 1;
                long long rc = rcnts[i + j - 1] + 1;
                res += lc * rc;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums;
    int m, k;
    nums = {3, 1, 9, 6};
    m = 3, k = 0;
    cout << Solution().countInterestingSubarrays(nums, m, k) << endl;
    return 0;
}
