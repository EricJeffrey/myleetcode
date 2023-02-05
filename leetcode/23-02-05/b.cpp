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
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries) {
        vector<int> pref(words.size() + 1, 0);
        auto isok = [](string &w) {
            const static string s = "aeiou";
            int u = 0;
            for (int i = 0; i < 5; i++) {
                if (w.front() == s[i]) {
                    u += 1;
                    break;
                }
            }
            for (int i = 0; i < 5; i++) {
                if (w.back() == s[i]) {
                    u += 1;
                    break;
                }
            }
            return (u == 2);
        };
        for (int i = 0; i < words.size(); i++) {
            pref[i + 1] = pref[i] + (isok(words[i]) ? 1 : 0);
            // cout << "pref: " << i + 1 << ", " << pref[i + 1] << endl;
        }
        vector<int> ans;
        for (auto &&vec : queries) {
            int l = vec[0] + 1;
            int r = vec[1] + 1;
            ans.push_back(pref[r] - pref[l - 1]);
        }
        return ans;
    }
};