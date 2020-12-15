#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        typedef vector<int> VI;
        vector<vector<VI>> dp;
        for (int i = 0; i <= target; i++)
            dp.push_back({});
        if (candidates.size() <= 0)
            return dp[target];
        // first
        dp[0].push_back({});
        int tmp = candidates[0];
        VI tmpvec = {tmp};
        while (tmp <= target) {
            dp[tmp].push_back(tmpvec);
            tmp += candidates[0];
            tmpvec.push_back(candidates[0]);
        }
        // every candidate
        for (int i = 1; i < (int)candidates.size(); i++) {
            int v = candidates[i];
            for (int j = v; j <= target; j++) {
                for (int k = 0; k < (int)dp[j - v].size(); k++) {
                    tmpvec = dp[j - v][k];
                    tmpvec.push_back(v);
                    dp[j].push_back(tmpvec);
                }
            }
        }
        return dp[target];
    }
};

int main(int argc, char const *argv[]) {
    vector<int> vec = {2, 3, 6, 7};
    int target = 23;
    vector<vector<int>> res = Solution().combinationSum(vec, target);
    for (auto &&tmpvec : res) {
        for (auto &&tmp : tmpvec)
            cout << tmp << ", ";
        cout << endl;
    }

    return 0;
}
