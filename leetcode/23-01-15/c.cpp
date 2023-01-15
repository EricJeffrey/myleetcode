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
    long long countGood(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        unordered_map<int, int> mp;
        long long curk = 0;
        int i = 0, j = 1;
        mp[nums[i]] = 1;
        long long res = 0;
        while (i < n && j < n) {
            int u = nums[j];
            if (mp.find(u) != mp.end()) {
                curk += mp[u];
            }
            mp[u] += 1;
            while (curk >= k) {
                res += n - j;
                mp[nums[i]] -= 1;
                curk -= mp[nums[i]];
                i += 1;
            }
            j += 1;
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums;
    int k;
    nums = {1, 2, 1, 1};
    k = 1;
    cout << Solution().countGood(nums, k) << endl;
    return 0;
}
