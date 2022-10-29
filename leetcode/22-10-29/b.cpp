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
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary) {
        auto getDis = [](const string &s1, const string &s2) {
            int res = 0;
            for (size_t i = 0; i < s1.size(); i++) {
                if (s1[i] != s2[i]) res += 1;
            }
            return res;
        };
        vector<vector<int>> distances(queries.size(), vector<int>(dictionary.size()));
        for (size_t i = 0; i < queries.size(); i++) {
            for (size_t j = 0; j < dictionary.size(); j++) {
                distances[i][j] = getDis(queries[i], dictionary[j]);
            }
        }
        vector<string> res;
        for (size_t i = 0; i < queries.size(); i++) {
            if (*min_element(distances[i].begin(), distances[i].end()) <= 2)
                res.push_back(queries[i]);
        }
        return res;
    }
};