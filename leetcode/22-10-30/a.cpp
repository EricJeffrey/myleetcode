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
    int averageValue(vector<int> &nums) {
        int sum = 0;
        int cnt = 0;
        for (auto &&v : nums) {
            if (v % 2 == 0 && v % 3 == 0) {
                sum += v;
                cnt += 1;
            }
        }
        return cnt == 0 ? 0 : sum / cnt;
    }
};