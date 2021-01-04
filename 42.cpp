#include <algorithm>
#include <array>
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
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        if (height.empty())
            return 0;
        const int sz = (int)height.size();
        int res = 0;
        int lMaxV = height[0], rMaxV = height[sz - 1];
        int l = 0, r = sz - 1;
        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] >= lMaxV) {
                    lMaxV = height[l];
                } else {
                    res += lMaxV - height[l];
                }
                l++;
            } else {
                if (height[r] >= rMaxV) {
                    rMaxV = height[r];
                } else {
                    res += rMaxV - height[r];
                }
                r--;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    auto runtest = [](vector<int> height) { cout << Solution().trap(height) << endl; };
    runtest({2, 0, 2});
    runtest({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
    runtest({4, 2, 0, 3, 2, 5});
    runtest({7, 7, 0, 4, 8, 6, 3, 8, 2, 7, 4, 4, 9, 8, 2, 9, 3, 10, 9, 7});
    return 0;
}
