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
    void nextPermutation(vector<int> &nums) {
        const int n = nums.size();
        if (n <= 1)
            return;
        int i;
        for (i = n - 2; i >= 0; i--)
            if (nums[i] < nums[i + 1])
                break;
        if (i < 0)
            return sort(nums.begin(), nums.end());
        else {
            int tmp = nums[i];
            sort(nums.begin() + i, nums.end());
            vector<int>::iterator it = upper_bound(nums.begin() + i, nums.end(), tmp);
            tmp = *it;
            nums.erase(it);
            nums.insert(nums.begin() + i, tmp);
        }
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums = {1, 3, 3, 2, 2};
    Solution().nextPermutation(nums);
    for (int v : nums)
        cout << v << ", ";
    cout << endl;
    return 0;
}

/*
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

1 2 3 5 5
2 5 5 3 1
3 1 2 5 5

1 3 2 3 2
1 3 3 2 2
*/