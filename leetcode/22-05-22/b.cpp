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
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (size_t i = 0; i < rocks.size(); i++) {
            q.push(capacity[i] - rocks[i]);
        }
        int res = 0;
        while (!q.empty()) {
            int u = q.top();
            q.pop();
            if (u > additionalRocks)
                break;
            additionalRocks -= u;
            res += 1;
        }
        return res;
    }
};