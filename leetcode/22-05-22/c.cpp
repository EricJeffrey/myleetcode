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
    int minimumLines(vector<vector<int>> &stockPrices) {
        sort(stockPrices.begin(), stockPrices.end(), [](const vector<int> &t1, const vector<int> &t2) {
            return t1[0] < t2[0];
        });
        if (stockPrices.size() == 1)
            return 0;
        int res = 1;
        long long y = (stockPrices[1][1] - stockPrices[0][1]);
        long long x = (stockPrices[1][0] - stockPrices[0][0]);

        for (size_t i = 2; i < stockPrices.size(); i++) {
            long long tmpy = (stockPrices[i][1] - stockPrices[i - 1][1]);
            long long tmpx = (stockPrices[i][0] - stockPrices[i - 1][0]);
            if (y * tmpx != tmpy * x) {
                res += 1;
                x = tmpx;
                y = tmpy;
            }
        }
        return res;
    }
};