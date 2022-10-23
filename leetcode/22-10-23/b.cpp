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

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    if (x % y == 0) return y;
    return gcd(y, x % y);
}

class Solution {
public:
    int subarrayGCD(vector<int> &nums, int k) {
        if (nums.size() == 1) {
            return nums[0] == k ? 1 : 0;
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == k) res += 1;
            int lastGcd = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int u = gcd(nums[j], lastGcd);
                cout << u << endl;
                if (u == k) {
                    res += 1;
                } else if (u % k == 0) {
                    lastGcd = u;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
