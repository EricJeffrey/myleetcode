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

p / v * (v + 1) = (pv + p) / v = p + p / v

 */

class Solution {
public:
    int maximumProduct(vector<int> &nums, int k) {
        typedef pair<int, size_t> pii;
        const int mod = 1e9 + 7;
        set<pii> s;
        for (size_t i = 0; i < nums.size(); i++) {
            int v = nums[i];
            if (v == 0) {
                v = 1;
                k -= 1;
            }
            s.insert(make_pair(v, i));
        }
        if (k < 0)
            return 0;
        for (int i = 0; i < k; i++) {
            pii tmp = *s.begin();
            s.erase(s.begin());
            tmp.first += 1;
            s.insert(tmp);
        }
        int64_t res = 1;
        for (auto &&tmp : s) {
            res *= tmp.first;
            res %= mod;
        }
        return int(res);
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums;
    int k;
    nums = {0, 4};
    k = 5;
    cout << Solution().maximumProduct(nums, k) << endl;
    nums = {6, 3, 3, 2};
    k = 2;
    cout << Solution().maximumProduct(nums, k) << endl;
    return 0;
}
