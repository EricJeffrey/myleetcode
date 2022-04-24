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
    int countLatticePoints(vector<vector<int>> &circles) {
        int minx = -100;
        int maxx = 200;
        int res = 0;
        for (int x = minx; x <= maxx; x++) {
            for (int y = minx; y <= maxx; y++) {
                bool got = false;
                for (auto &&vec : circles) {
                    int xi = vec[0], yi = vec[1], r = vec[2];
                    if ((x - xi) * (x - xi) + (y - yi) * (y - yi) <= r * r) {
                        got = true;
                    }
                }
                if (got)
                    res += 1;
            }
        }
        return res;
    }
};