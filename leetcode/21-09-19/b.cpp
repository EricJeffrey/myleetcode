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
    int sumOfBeauties(vector<int> &nums) {
        multiset<int> pre, suf;
        for (size_t i = 0; i < nums.size(); i++) {
            suf.insert(nums[i]);
        }
        pre.insert(nums[0]);
        suf.erase(suf.find(nums[0]));
        vector<int> reslist;
        int res = 0;
        for (size_t i = 1; i < nums.size() - 1; i++) {
            int v = nums[i];
            suf.erase(suf.find(v));
            if (v > *pre.rbegin() && v < *suf.begin()) {
                res += 2;
            } else if (v > nums[i - 1] && v < nums[i + 1]) {
                res += 1;
            }
            pre.insert(v);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) { return 0; }
