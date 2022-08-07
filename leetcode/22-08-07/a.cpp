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
    int arithmeticTriplets(vector<int> &nums, int diff) {
        int res = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                for (size_t k = j + 1; k < nums.size(); k++) {
                    if (nums[k] - nums[j] == diff && nums[j] - nums[i] == diff) {
                        res += 1;
                    }
                }
            }
        }
        return res;
    }
};