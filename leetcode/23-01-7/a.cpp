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
    string categorizeBox(int length, int width, int height, int mass) {
        bool isBulky = ((long long)length) * width * height >= 1e9 ||
                       !(length < 1e4 && width < 1e4 && height < 1e4);
        bool isHeavy = mass >= 100;
        if (isBulky && isHeavy) {
            return "Both";
        } else if (!isBulky && !isHeavy) {
            return "Neither";
        } else if (isBulky) {
            return "Bulky";
        } else {
            return "Heavy";
        }
    }
};
