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
    string largestPalindromic(string num) {
        int cnts[10] = {};
        for (auto &&c : num) {
            cnts[c - '0'] += 1;
        }
        string tmp;
        for (int i = 10 - 1; i > 0; i--) {
            if (cnts[i] > 1) {
                tmp.append(cnts[i] / 2, i + '0');
                cnts[i] %= 2;
            }
        }
        if (!tmp.empty() && cnts[0] > 1) {
            tmp.append(cnts[0] / 2, '0');
            cnts[0] %= 2;
        }
        int midChar = -1;
        for (int i = 10 - 1; i >= 0; i--) {
            if (cnts[i] > 0) {
                midChar = i + '0';
                break;
            }
        }
        string tmp2 = tmp;
        reverse(tmp2.begin(), tmp2.end());
        if (midChar != -1) {
            return tmp + (char)midChar + tmp2;
        }
        return tmp + tmp2;
    }
};