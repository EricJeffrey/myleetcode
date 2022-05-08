#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
    bool canJump(vector<int> &nums) {
        const int n = nums.size();
        if (n <= 0)
            return 0;
        int rea_max = 0;
        for (int i = 0; i < n; i++) {
            if (i > rea_max)
                break;
            rea_max = max(rea_max, i + nums[i]);
            if (rea_max >= n - 1)
                return 1;
        }
        return 0;
    }
};
int main(int argc, char const *argv[]) { return 0; }
