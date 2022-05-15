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
    vector<string> removeAnagrams(vector<string> &words) {
        int cnt[26] = {};
        for (auto &&c : words[0])
            cnt[c - 'a'] += 1;
        set<size_t> toremove;
        for (size_t i = 1; i < words.size(); i++) {
            int tmpcnt[26] = {};
            for (auto &&c : words[i])
                tmpcnt[c - 'a'] += 1;
            bool same = true;
            for (int i = 0; i < 26; i++) {
                if (tmpcnt[i] != cnt[i]) {
                    same = false;
                    break;
                }
            }
            if (same) {
                toremove.insert(i);
            } else {
                for (int i = 0; i < 26; i++)
                    cnt[i] = tmpcnt[i];
            }
        }
        vector<string> res;
        for (size_t i = 0; i < words.size(); i++) {
            if (toremove.count(i) == 0)
                res.push_back(words[i]);
        }
        return res;
    }
};