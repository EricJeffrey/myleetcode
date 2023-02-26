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
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans(word.size(), 0);
        long long t = 0;
        for (int i = 0; i < word.size(); i++) {
            int u = word[i] - '0';
            if ((t * 10 + u) % m == 0) {
                ans[i] = 1;
            }
            t = (t * 10 + u) % m;
        }
        return ans;
    }
};