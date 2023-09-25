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
    int numberOfPoints(vector<vector<int>> &nums) {
        bool coverd[101] = {};
        for (int i = 1; i <= 100; i++) {
            for (auto &&vec : nums) {
                int s = vec[0], e = vec[1];
                if (i >= s && i <= e) {
                    coverd[i] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= 100; i++) {
            res += coverd[i] ? 1 : 0;
        }
        return res;
    }
};