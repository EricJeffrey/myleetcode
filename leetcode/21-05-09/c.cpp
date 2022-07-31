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
#include <vector>
using namespace std;

// [start, end)
int dfs(vector<int> &nums, int start, int end) {}

class Solution {
public:
    int maxSumMinProduct(vector<int> &nums) {
        nums.push_back(0);
        vector<long long> prefixSum;
        prefixSum.reserve(nums.size());
        for (size_t i = 0; i < nums.size(); i++) {
            prefixSum[i] = nums[i] + (i == 0 ? 0 : prefixSum[i - 1]);
        }
        // [s, e)
        auto sumOfIJ = [&prefixSum](int s, int e) {
            return prefixSum[e - 1] - (s <= 0 ? 0 : prefixSum[s - 1]);
        };

        struct Tmp {
            int value;
            // [start, end)
            int start, end;
            long long childValMax;
            Tmp(int val, int s, int e) {
                value = val;
                childValMax = ((long long)val) * val;
                start = s, end = e;
            }
        };
        stack<Tmp> s;
        s.push(Tmp{nums[0], 0, 1});
        for (int i = 1; i < nums.size(); i++) {
            int v = nums[i];
            auto tmpTopV = s.top().value;
            if (v > tmpTopV) {
                s.push(Tmp{v, i, i + 1});
            } else if (v == tmpTopV) {
                auto &tmpTop = s.top();
                tmpTop.end = i + 1;
                tmpTop.childValMax = max(tmpTop.childValMax, v * sumOfIJ(tmpTop.start, i + 1));
            } else if (v < tmpTopV) {
                auto lastTop = s.top();
                s.pop();
                while (!s.empty() && v < s.top().value) {
                    auto &newTop = s.top();
                    int newStart = min(newTop.start, lastTop.start);
                    int newEnd = max(newTop.end, lastTop.end);
                    lastTop.childValMax =
                        max(lastTop.childValMax,
                            max(newTop.childValMax, newTop.value * sumOfIJ(newStart, newEnd)));
                    lastTop.start = newStart;
                    lastTop.end = newEnd;
                    s.pop();
                }
                if (s.empty()) {
                    Tmp newNode{v, 0, i + 1};
                    newNode.childValMax =
                        max(newNode.childValMax, max(v * (sumOfIJ(0, i + 1)), lastTop.childValMax));
                    s.push(newNode);
                } else {
                    if (v == s.top().value) {
                        auto &tmpTop = s.top();
                        tmpTop.end = i + 1;
                        tmpTop.childValMax = max(v * sumOfIJ(tmpTop.start, i + 1),
                                                 max(tmpTop.childValMax, lastTop.childValMax));
                    } else {
                        Tmp newNode{v, lastTop.start, i + 1};
                        newNode.childValMax =
                            max(newNode.childValMax,
                                max(v * sumOfIJ(lastTop.start, i + 1), lastTop.childValMax));
                        s.push(newNode);
                    }
                }
            }
        }
        return (int)(s.top().childValMax % (int)(1e9 + 7));
    }
};

int main(int argc, char const *argv[]) {

    vector<int> nums;
    nums = {7, 3, 7, 10, 4, 16, 3, 2, 15, 18, 13, 1, 11};
    cout << Solution().maxSumMinProduct(nums) << endl;
    nums = {1, 2, 3, 2};
    cout << Solution().maxSumMinProduct(nums) << endl;
    nums = {2, 3, 3, 1, 2};
    cout << Solution().maxSumMinProduct(nums) << endl;
    nums = {3, 1, 5, 6, 4, 2};
    cout << Solution().maxSumMinProduct(nums) << endl;
    return 0;
}
