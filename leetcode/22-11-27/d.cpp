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

/*
对左边每一个<la, sm>，要找右边 la-sm

2小4大 - 1小0大/2小0大
2小5大 - 2小0大/3小0大
5小2大 - 3大/4大
4小2大 -

a小b大
    差值 - 大减小
    a = b - 不找/差值1
    a < b - 差值 (a-b),(a-b+1)
    a > b - 差值 (a-b) (a-b+1)
*/

class Solution {
public:
    int countSubarrays(vector<int> &nums, int k) {
        int n = nums.size();
        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) {
                pos = i;
                break;
            }
        }
        map<int, int> rightDiffCnts;
        int minCnt = 0, maxCnt = 0;
        for (int i = pos + 1; i < n; i++) {
            if (nums[i] < k)
                minCnt++;
            else
                maxCnt++;
            rightDiffCnts[maxCnt - minCnt] += 1;
        }
        int res = 1;
        res += rightDiffCnts[1] + rightDiffCnts[0];
        minCnt = 0, maxCnt = 0;
        for (int i = pos - 1; i >= 0; i--) {
            if (nums[i] < k) minCnt++;
            if (nums[i] > k) maxCnt++;
            if (minCnt == maxCnt || maxCnt - minCnt == 1) res += 1;
            res += rightDiffCnts[minCnt - maxCnt] + rightDiffCnts[minCnt - maxCnt + 1];
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums;
    int k;
    nums = {3, 2, 1, 4, 5}, k = 4;
    cout << Solution().countSubarrays(nums, k) << endl;
    nums = {2, 3, 1}, k = 3;
    cout << Solution().countSubarrays(nums, k) << endl;
    nums = {2, 5, 1, 4, 3, 6};
    k = 1;
    cout << Solution().countSubarrays(nums, k) << endl;
    return 0;
}
