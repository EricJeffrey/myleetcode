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
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        const int maxn = 1e5 + 5;
        vector<int> cntofw(maxn, 0), cntofl(maxn, 0);
        for (auto &&vec : matches) {
            cntofw[vec[0]] += 1;
            cntofl[vec[1]] += 1;
        }
        vector<int> ans1, ans2;
        for (int i = 1; i < maxn; i++) {
            if (cntofw[i] > 0 || cntofl[i] > 0) {
                if (cntofl[i] == 0)
                    ans1.push_back(i);
                if (cntofl[i] == 1)
                    ans2.push_back(i);
            }
        }
        return {ans1, ans2};
    }
};