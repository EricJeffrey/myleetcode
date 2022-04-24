#include <algorithm>
#include <array>
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
#include <vector>
using namespace std;

class Solution {
public:
    string maxValue(string n, int x) {
        string res = n;
        bool isnegative = false;
        isnegative = n[0] == '-';
        if (isnegative) {
            for (size_t i = 1; i < n.size(); i++) {
                if (n[i] - '0' > x) {
                    res.insert(res.begin() + i, x + '0');
                    break;
                }
            }
            if (res.size() == n.size())
                res += x + '0';
        } else {
            for (size_t i = 0; i < n.size(); i++) {
                if (n[i] - '0' < x) {
                    res.insert(res.begin() + i, x + '0');
                    break;
                }
            }
            if (res.size() == n.size())
                res += x + '0';
        }
        return res;
    }
};

int main(int argc, char const *argv[]) { return 0; }
