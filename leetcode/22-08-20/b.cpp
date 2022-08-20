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
    int secondsToRemoveOccurrences(string s) {
        int res = 0;
        vector<size_t> posToFlip;
        while (true) {
            // flip
            posToFlip.clear();
            for (size_t i = 0; i < s.size(); i++) {
                if (s[i] == '0' && i + 1 < s.size() && s[i + 1] == '1') {
                    posToFlip.push_back(i);
                }
            }
            if (posToFlip.empty()) {
                break;
            }
            for (auto &&v : posToFlip) {
                swap(s[v], s[v + 1]);
            }
            res += 1;
        }
        return res;
    }
};