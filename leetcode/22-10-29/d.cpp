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
    vector<int> secondGreaterElement(vector<int> &nums) {
        const int n = nums.size();
        // {value, index}
        vector<pair<int, int>> firstMax(nums.size(), {-1, -1});
        {
            stack<pair<int, int>> st;
            st.push({nums.back(), n - 1});
            for (int i = n - 2; i >= 0; i--) {
                int u = nums[i];
                while (!st.empty() && u >= st.top().first)
                    st.pop();
                if (st.empty())
                    firstMax[i] = {-1, -1};
                else
                    firstMax[i] = st.top();
                st.push({u, i});
            }
        }
        // {value, index}
        vector<vector<pair<int, int>>> candies(nums.size());
        for (int i = 0; i < n; i++) {
            int u = nums[i];
            if (firstMax[i].second != -1) {
                candies[firstMax[i].second].push_back({u, i});
            }
        }
        vector<int> res(nums.size(), -1);
        stack<int> st;
        st.push(nums.back());
        for (int i = n - 2; i >= 0; i--) {
            int u = nums[i];
            if (!candies[i].empty()) {
                stack<int> tmpst = st;
                for (int j = candies[i].size() - 1; j >= 0; j--) {
                    auto p = candies[i][j];
                    int tmpVal = p.first;
                    int who = p.second;
                    while (!tmpst.empty() && tmpVal >= tmpst.top()) {
                        tmpst.pop();
                    }
                    if (!tmpst.empty()) {
                        res[who] = tmpst.top();
                    }
                }
            }
            while (!st.empty() && u > st.top())
                st.pop();
            st.push(u);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums, res;
    auto output = [&res]() {
        for (auto &&v : res) {
            cout << v << ",";
        }
        cout << endl;
    };
    nums = {2, 4, 0, 9, 6};
    res = Solution().secondGreaterElement(nums);
    output();
    nums = {3, 3};
    res = Solution().secondGreaterElement(nums);
    output();
    nums = {2, 4, 4, 0, 9, 9, 6};
    res = Solution().secondGreaterElement(nums);
    output();
    nums = {11, 20, 2, 4, 18, 18, 1, 11, 3, 9};
    res = Solution().secondGreaterElement(nums);
    output();
    return 0;
}
