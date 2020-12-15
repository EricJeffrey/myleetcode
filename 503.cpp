#include <algorithm>
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

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        const int sz = nums.size();
        nums.resize(sz * 2);
        for (int i = sz; i < sz * 2; i++) {
            nums[i] = nums[i - sz];
        }
        vector<int> nextGreaterIndex(sz * 2, -1);
        {
            stack<int> tmpIndexStack;
            for (int i = 0; i < sz * 2; i++) {
                while (!tmpIndexStack.empty() && nums[tmpIndexStack.top()] < nums[i]) {
                    nextGreaterIndex[tmpIndexStack.top()] = i;
                    tmpIndexStack.pop();
                }
                tmpIndexStack.push(i);
            }
        }
        vector<int> res;
        for (int i = 0; i < sz; i++)
            if (nextGreaterIndex[i] != -1)
                res.push_back(nums[nextGreaterIndex[i]]);
            else if (nextGreaterIndex[i + sz] != -1)
                res.push_back(nums[nextGreaterIndex[i + sz]]);
            else
                res.push_back(-1);
        return res;
    }
};

int main(int argc, char const *argv[]) {
    auto testout = [](vector<int> nums) {
        auto res = Solution().nextGreaterElements(nums);
        for (auto &&v : res) {
            cout << v << " ";
        }
        cout << endl;
    };
    testout({3, 7, 1, 4, 10, 7, 2, 10, 1, 3});
    return 0;
}
