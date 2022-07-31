#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;
class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        const int sz = nums.size();
        vector<int> res(sz);
        res[0] = 1;
        for (int i = 1; i < sz; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        for (int i = sz - 2; i >= 0; i--) {
            nums[i] *= nums[i + 1];
            res[i] *= nums[i + 1];
        }
        return res;
    }
};
int main(int argc, char const *argv[]) { return 0; }
