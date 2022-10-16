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
    bool sumOfNumberAndReverse(int num) {
        auto reversed = [](int x) {
            string tmp = to_string(x);
            reverse(tmp.begin(), tmp.end());
            return stoi(tmp);
        };
        for (int i = num / 2 + (num % 2 != 0 ? 1 : 0); i <= num; i++) {
            if (i + reversed(i) == num) {
                return true;
            }
        }
        return false;
    }
};
