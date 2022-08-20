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
    vector<long long> maximumSegmentSum(vector<int> &nums, vector<int> &removeQueries) {
        struct T {
            int start;
            long long sum;
            int len;
        };
        vector<long long> res(nums.size(), 0);
        map<int, T> sumFromI, sumEndI;
        T curMaxSum{.start = removeQueries.back(), .sum = nums[removeQueries.back()], .len = 1};
        sumFromI[removeQueries.back()] = curMaxSum;
        sumEndI[removeQueries.back()] = curMaxSum;
        for (int i = removeQueries.size() - 2; i >= 0; i--) {
            res[i] = curMaxSum.sum;
            int index = removeQueries[i];
            T cur{.start = index, .sum = nums[index], .len = 1};
            if (sumFromI.find(index + 1) != sumFromI.end()) {
                cur.sum += sumFromI[index + 1].sum;
                cur.len += sumFromI[index + 1].len;
                sumFromI.erase(index + 1);
            }
            if (sumEndI.find(index - 1) != sumEndI.end()) {
                cur.start = index - sumEndI[index - 1].len;
                cur.sum += sumEndI[index - 1].sum;
                cur.len += sumEndI[index - 1].len;
                sumEndI.erase(index - 1);
            }
            sumFromI[cur.start] = cur;
            sumEndI[cur.start + cur.len - 1] = cur;
            if (cur.sum > curMaxSum.sum) {
                curMaxSum = cur;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums, removeQueries;
    auto test = [&]() {
        auto res = Solution().maximumSegmentSum(nums, removeQueries);
        for (auto &&v : res) {
            cout << v << " ";
        }
        cout << endl;
    };
    nums = {1, 2, 5, 6, 1}, removeQueries = {0, 3, 2, 4, 1};
    test();
    nums = {3, 2, 11, 1}, removeQueries = {3, 2, 1, 0};
    test();

    return 0;
}
