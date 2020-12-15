#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        const int sz = nums.size();
        vector<vector<int>> res((1 << sz));
        for (int i = 0; i < (1 << sz); i++) {
            int x = i, tmpj = 0;
            while (x > 0) {
                if (x & 1)
                    res[i].push_back(nums[tmpj]);
                tmpj += 1;
                x >>= 1;
            }
        }
        return res;
    }
};

int main() {}