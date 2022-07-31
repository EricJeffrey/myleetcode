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
    int getMinimumTime(vector<int> &time, vector<vector<int>> &fruits, int limit) {
        int res = 0;
        for (auto &&vec : fruits) {
            int type = vec[0];
            int num = vec[1];
            int cnt = num / limit;
            if (num % limit != 0)
                cnt += 1;
            res += time[type] * cnt;
        }
        return res;
    }
};
