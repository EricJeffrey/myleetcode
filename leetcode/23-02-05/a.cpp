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
    long long pickGifts(vector<int> &gifts, int k) {
        priority_queue<int> gq;
        for (auto &&v : gifts) {
            gq.push(v);
        }
        for (int i = 0; i < k; i++)
        {
            int u = gq.top();
            gq.pop();
            gq.push((int)floor(sqrt(u)));
        }
        long long res = 0;
        while (!gq.empty()) {
            res += gq.top();
            gq.pop();
        }
        return res;
    }
};