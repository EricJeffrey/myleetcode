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
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids,
                                              vector<int> &views) {
        struct Tmp {
            int view;
            string id;
            bool operator<(const Tmp &t) const {
                return view == t.view ? id < t.id : view > t.view;
            }
        };

        map<string, vector<Tmp>> creator2Videos;
        for (size_t i = 0; i < views.size(); i++) {
            creator2Videos[creators[i]].push_back({views[i], ids[i]});
        }
        int64_t maxLiuxingdu = INT_MIN;
        map<string, int64_t> liuxingdu;
        for (auto &&p : creator2Videos) {
            sort(p.second.begin(), p.second.end());
            int64_t tmp = 0;
            for (auto &&v : p.second) {
                tmp += v.view;
            }
            liuxingdu[p.first] = tmp;
            maxLiuxingdu = max(maxLiuxingdu, tmp);
        }
        vector<string> targets;
        for (auto &&p : creator2Videos) {
            if (liuxingdu[p.first] == maxLiuxingdu) {
                targets.push_back(p.first);
            }
        }
        vector<vector<string>> res;
        for (auto &&target : targets) {
            res.push_back({target, creator2Videos[target].front().id});
        }
        return res;
    }
};