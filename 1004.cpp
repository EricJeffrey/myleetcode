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
    int longestOnes(vector<int> &A, int K) {
        if (A.empty()) return 0;
        bool startWith1 = (A[0] == 1 ? true : false);
        vector<pair<int, int>> blocks;
        int res = 0;
        {
            int curCount = 1, who = A[0];
            for (size_t i = 1; i < A.size(); i++) {
                if (A[i] == who) {
                    curCount++;
                } else {
                    blocks.push_back(make_pair(curCount, who));
                    if (who == 1) res = max(res, curCount);
                    curCount = 1, who = A[i];
                }
            }
            blocks.push_back(make_pair(curCount, who));
            if (who == 1) res = max(res, curCount);
        }
        res = min((int)A.size(), res + K);
        bool fir = true;
        deque<pair<int, int>> q;
        int tmpRes = 0, curIndex = 0, curK = 0;
        while (true) {
            while (curIndex < blocks.size() && curK <= K) {
                res = max(tmpRes + (K - curK), res);
                auto &tmp = blocks[curIndex];
                q.push_back(tmp);
                tmpRes += tmp.first;
                if (tmp.second == 0) curK += tmp.first;
                curIndex++;
            }
            while (curK > K && !q.empty()) {
                auto &tmp = q.front();
                if (tmp.second == 0) curK -= tmp.first;
                tmpRes -= tmp.first;
                q.pop_front();
            }
            res = max(tmpRes + (K - curK), res);
            // meet a huge block 0
            if (q.empty() && curIndex < blocks.size()) {
                curIndex++;
                continue;
            }
            // all block 0 sum < K, nothing to do
            if (curIndex >= blocks.size())
                break;
        }
        return min((int)A.size(), res);
    }
};

int main(int argc, char const *argv[]) {
    vector<int> a;
    int k;
    a = {1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1};
    k = 8;
    cout << Solution().longestOnes(a, k) << endl;
    return 0;
}
