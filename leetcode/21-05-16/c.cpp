#include <algorithm>
#include <array>
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

class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> cntOfNums2;

    FindSumPairs(vector<int> &nums1, vector<int> &nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (auto &&v : nums2) {
            if (cntOfNums2.find(v) == cntOfNums2.end())
                cntOfNums2[v] = 1;
            else
                cntOfNums2[v] += 1;
        }
    }

    void add(int index, int val) {
        int oldVal = nums2[index];
        cntOfNums2[oldVal] -= 1;
        int newVal = oldVal + val;
        nums2[index] = newVal;
        cntOfNums2[newVal] += 1;
    }

    int count(int tot) {
        int res = 0;
        for (auto &&v : nums1) {
            if (tot - v >= 0 && cntOfNums2.find(tot - v) != cntOfNums2.end())
                res += cntOfNums2[tot - v];
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums1;
    vector<int> nums2;
    nums1 = {1, 1, 2, 2, 2, 3};
    nums2 = {1, 4, 5, 2, 5, 4};
    return 0;
}
