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
    int bestClosingTime(string customers) {
        vector<int> ysafter(customers.size(), 0);
        vector<int> nsbefore(customers.size(), 0);
        for (size_t i = 0; i < customers.size(); i++) {
            if (i == 0) {
                nsbefore[i] = (customers[i] == 'N' ? 1 : 0);
            } else {
                nsbefore[i] = nsbefore[i - 1];
                if (customers[i] == 'N') {
                    nsbefore[i] += 1;
                }
            }
        }
        for (int j = customers.size() - 1; j >= 0; j--) {
            if (j == customers.size() - 1) {
                ysafter[j] = (customers[j] == 'Y' ? 1 : 0);
            } else {
                ysafter[j] = ysafter[j + 1];
                if (customers[j] == 'Y') {
                    ysafter[j] += 1;
                }
            }
        }
        int minVal = INT32_MAX, index = -1;
        for (int i = 0; i < customers.size() + 1; i++) {
            int tmpCost = 0;
            if (i == 0) {
                tmpCost = ysafter[i];
            } else if (i == customers.size()) {
                tmpCost = nsbefore[customers.size() - 1];
            } else {
                tmpCost = nsbefore[i - 1] + ysafter[i];
            }
            if (tmpCost < minVal) {
                minVal = tmpCost;
                index = i;
            }
        }
        return index;
    }
};