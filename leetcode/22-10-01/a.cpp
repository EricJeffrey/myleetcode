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
    bool allSame(int cnt[]) {
        int v = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                if (v == -1 ) v = cnt[i];
                else if (cnt[i] != v) return false;
            }
        }
        return true;
    }
    bool equalFrequency(string word) {
        int cnt[26] = {};
        for (auto &&ch : word) {
            cnt[ch - 'a'] += 1;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            cnt[i] -= 1;
            if (allSame(cnt)) return true;
            cnt[i] += 1;
        }
        return false;
        
    }
};
