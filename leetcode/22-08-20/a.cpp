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
    int minimumRecolors(string blocks, int k) {
        int res = INT32_MAX;
        for (size_t i = 0; i < blocks.size() - k + 1; i++) {
            int cnt = 0;
            for (int j = 0; j < k; j++) {
                if (blocks[i + j] == 'W') {
                    cnt += 1;
                }
            }
            res = min(res, cnt);
        }
        return res;
    }
};