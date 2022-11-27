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
    int pivotInteger(int n) {
        int sum = (1 + n) * n / 2;
        int tmp = 0;
        for (int i = 0; i <= n; i++) {
            tmp += i;
            if (tmp * 2 == sum + i) {
                return i;
            }
        }
        return -1;
    }
};
