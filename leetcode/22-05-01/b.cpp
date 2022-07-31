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
    int minimumCardPickup(vector<int> &cards) {
        unordered_map<int, int> lastOccrI;
        int res = INT32_MAX;
        for (int i = 0; i < cards.size(); i++) {
            const int v = cards[i];
            if (lastOccrI.find(v) != lastOccrI.end()) {
                res = min(res, i - lastOccrI[v] + 1);
            }
            lastOccrI[v] = i;
        }
        return res == INT32_MAX ? -1 : res;
    }
};