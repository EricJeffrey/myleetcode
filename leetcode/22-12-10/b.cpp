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
    int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k) {
        int n = vals.size();
        vector<vector<int>> graph(n);
        for (auto &&vec : edges) {
            int u = vec[0], v = vec[1];
            graph[u].push_back(vals[v]);
            graph[v].push_back(vals[u]);
        }
        for (size_t j = 0; j < graph.size(); j++) {
            vector<int> &vec = graph[j];
            sort(vec.begin(), vec.end(), greater<int>());
        }
        int res = *min_element(vals.begin(), vals.end());
        for (size_t i = 0; i < graph.size(); i++) {
            auto &vec = graph[i];
            int tmp = 0;
            for (size_t j = 0; j < vec.size() && j < k && vec[j] > 0; j++) {
                tmp += vec[j];
            }
            tmp += vals[i];
            res = max(res, tmp);
        }
        return res;
    }
};