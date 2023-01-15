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
    int differenceOfSum(vector<int> &nums) {
        int sum = 0;
        for (auto &&v : nums) {
            sum += v;
        }
        int bitsum = 0;
        for (auto &&v : nums) {
            while (v != 0) {
                bitsum += v % 10;
                v /= 10;
            }
        }
        return abs(sum - bitsum);
    }
};