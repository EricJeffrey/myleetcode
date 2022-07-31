
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        int len = nums.size();
        return findkth(nums, 0, len, len - k + 1);
    }
    int findkth(vector<int> &nums, int st, int len, int k) {
        srand(time(NULL));
        int pivot = rand() % len + st;
        // cout << pivot << ' ';
        swap(nums[st], nums[pivot]);
        pivot = st;
        int i = st, j = st + len - 1;
        while (true) {
            while (j >= st && nums[j] >= nums[pivot])
                j--;
            while (i < st + len && nums[i] < nums[pivot])
                i++;
            if (i >= j) {
                pivot = i;
                break;
            }
            swap(nums[i], nums[j]);
        }
        int tmp = pivot - st + 1;
        if (tmp == k)
            return nums[pivot];
        if (tmp < k)
            return findkth(nums, pivot + 1, len - tmp, k - tmp);
        else
            return findkth(nums, st, tmp - 1, k);
    }
};
int main(int argc, char const *argv[]) {
    vector<int> vec = {2, 3, 3, 9, 8, 1, 6};
    // for (int k = 1; k <= vec.size(); k++) {
    //     cout << Solution().findKthLargest(vec, k) << ' ';
    // }
    return 0;
}
