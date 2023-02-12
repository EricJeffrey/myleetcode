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
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>> &queries) {
        struct T {
            int i, j;
        };
        unordered_map<long long, T> mp;
        for (int i = 0; i < s.size(); i++) {
            long long last = 0;
            for (int j = i; j < s.size(); j++) {
                long long tmp = last * 2 + (s[j] - '0');
                if (j - i + 1 >= 32) {
                    break;
                }
                if (mp.find(tmp) != mp.end()) {
                    if (mp[tmp].j - mp[tmp].i > j - i) {
                        mp[tmp] = {i, j};
                    } else if (mp[tmp].j - mp[tmp].i == j - i && mp[tmp].i > i) {
                        mp[tmp] = {i, j};
                    }
                } else {
                    mp[tmp] = {i, j};
                }
                last = tmp;
            }
        }
        vector<int> q;
        for (auto &&vec : queries) {
            q.push_back(vec[0] ^ vec[1]);
        }
        vector<vector<int>> res;
        for (auto &&v : q) {
            if (mp.find(v) == mp.end()) {
                res.push_back({-1, -1});
            } else {
                res.push_back({mp[v].i, mp[v].j});
            }
        }
        return res;
    }
};