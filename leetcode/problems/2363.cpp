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
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1,
                                          vector<vector<int>> &items2) {
        map<int, int> mp;
        for (auto &&vec : items1) {
            int value = vec[0], weight = vec[1];
            if (mp.find(value) == mp.end())
                mp[value] = 0;
            mp[value] += weight;
        }
        for (auto &&vec : items2) {
            int value = vec[0], weight = vec[1];
            if (mp.find(value) == mp.end())
                mp[value] = 0;
            mp[value] += weight;
        }
        vector<vector<int>> res;
        for (auto &&p : mp) {
            res.push_back({p.first, p.second});
        }
        return res;
    }
};