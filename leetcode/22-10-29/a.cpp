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
    string oddString(vector<string> &words) {
        auto getDiff = [](const string &s) {
            vector<int> res;
            for (size_t j = 0; j <= s.size() - 2; j++) {
                res.push_back(s[j + 1] - s[j]);
            }
            return res;
        };
        vector<vector<int>> diffs;
        for (auto &&word : words) {
            diffs.push_back(getDiff(word));
        }
        struct Tmp {
            vector<int> values;
            bool operator<(const Tmp &t) const {
                for (size_t i = 0; i < values.size(); i++) {
                    if (t.values[i] != values[i]) return values[i] < t.values[i];
                }
                return false;
            }
        };
        map<Tmp, int> diffCnts;
        for (size_t i = 0; i < words.size(); i++) {
            Tmp tmp = {.values = diffs[i]};
            diffCnts[tmp] += 1;
        }
        for (size_t i = 0; i < words.size(); i++) {
            Tmp tmp = {.values = diffs[i]};
            if (diffCnts[tmp] == 1) return words[i];
        }
        return words.front();
    }
};

int main(int argc, char const *argv[]) {
    vector<string> words;
    words = {"adc", "wzy", "abc"};
    cout << Solution().oddString(words) << endl;
    words = {"aaa", "bob", "ccc", "ddd"};
    cout << Solution().oddString(words) << endl;
    return 0;
}
