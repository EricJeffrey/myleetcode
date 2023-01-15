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
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        int n = nums.size();
        long long res = 0;
        return res;
    }
};
/*

0  1  2   3   4  5   6  7   8  9   10  11  12 13 14
2, 7, 11, 11, 8, 11, 2, 11, 3, 11, 2,  10, 7, 4, 5

*/

int main(int argc, char const *argv[]) {
    vector<int> nums;
    int minK, maxK;
    nums = {1, 3, 5, 2, 7, 5}, minK = 1, maxK = 5;
    cout << Solution().countSubarrays(nums, minK, maxK) << endl;
    nums = {1, 1, 1, 1}, minK = 1, maxK = 1;
    cout << Solution().countSubarrays(nums, minK, maxK) << endl;
    nums = {35054,  398719, 945315, 945315, 820417, 945315, 35054, 945315,
            171832, 945315, 35054,  109750, 790964, 441974, 552913},
    minK = 35054, maxK = 945315;
    cout << Solution().countSubarrays(nums, minK, maxK) << endl;
    nums = {2, 7, 11, 11, 8, 11, 2, 11, 3, 11, 2, 10, 7, 4, 5}, minK = 2, maxK = 11;
    cout << Solution().countSubarrays(nums, minK, maxK) << endl;
    return 0;
}
