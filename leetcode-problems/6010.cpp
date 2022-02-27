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
    long long minimumTime(vector<int> &time, int totalTrips) {
        long long r = 1e12 + 1;
        long long l = 0;
        while (l < r) {
            long long mid = (l + r) >> 1;
            long long tmpsum = 0;
            for (auto &&v : time) {
                tmpsum += mid / v;
            }
            if (tmpsum < totalTrips) {
                l = mid + 1;
            }
            if (tmpsum >= totalTrips) {
                r = mid;
            }
        }
        return l;
    }
};