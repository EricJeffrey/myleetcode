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
    int destroyTargets(vector<int> &nums, int space) {
        /*
        space = 7
        13, 20, 5, 16, 3, 19, 18, 11, 3, 2, 26
        6   6   5  2   3  5   4   4   3  2, 5
         */
        sort(nums.begin(), nums.end());
        map<int, int> cntOfMods;
        for (auto &&v : nums) {
            cntOfMods[v % space] += 1;
        }
        int maxCnt = 0;
        for (auto &&p : cntOfMods) {
            maxCnt = max(p.second, maxCnt);
        }
        int minVal = 0;
        for (auto &&v : nums) {
            if (cntOfMods[v % space] == maxCnt) {
                minVal = v;
                break;
            }
        }
        return minVal;
    }
};