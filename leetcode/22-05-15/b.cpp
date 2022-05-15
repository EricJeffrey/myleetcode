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
    int maxConsecutive(int bottom, int top, vector<int> &special) {
        sort(special.begin(), special.end());
        int last = bottom;
        int res = 0;
        for (int i = 0; i < special.size(); i++) {
            res = max(res, special[i] - last);
            last = special[i] + 1;
        }
        res = max(res, top - special.back());
        return res;
    }
};