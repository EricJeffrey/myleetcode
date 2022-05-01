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
    string removeDigit(string number, char digit) {
        vector<string> ress;
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == digit) {
                string tmp = number;
                tmp.erase(tmp.begin() + i);
                ress.push_back(tmp);
            }
        }
        sort(ress.begin(), ress.end());
        return ress.back();
    }
};