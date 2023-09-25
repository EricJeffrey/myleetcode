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
    int findone(string num, string x) {
        int res = 0;
        int i = 0, j = 0;
        for (i = 0, j = 0; i < num.size() && j < x.size(); i++) {
            if (num[i] == x[j]) {
                j++;
            } else {
                res++;
            }
        }
        if (j == x.size())
            return res;
        else
            return num.size();
    }
    int minimumOperations(string num) {
        // 57 52 00 05
        reverse(num.begin(), num.end());
        int res = INT32_MAX;
        string targets[] = {"57", "52", "00", "05"};
        for (int i = 0; i < 4; i++) {
            res = min(res, findone(num, targets[i]));
        }
        res = min(res, int(num.size() - (int)count(num.begin(), num.end(), '0')));
        return res;
    }
};