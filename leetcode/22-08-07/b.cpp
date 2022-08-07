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
    void dfs(int cur, const vector<vector<int>> &g, vector<bool> &reachable,
             const set<int> &restr) {
        if (restr.find(cur) != restr.end())
            return;
        if (reachable[cur])
            return;
        reachable[cur] = true;
        for (auto &&v : g[cur]) {
            dfs(v, g, reachable, restr);
        }
    }
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted) {
        vector<vector<int>> graph(n, vector<int>());
        for (auto &&vec : edges) {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        set<int> restr(restricted.begin(), restricted.end());
        vector<bool> reachable(n, false);
        dfs(0, graph, reachable, restr);
        int res = 0;
        for (auto &&v : reachable) {
            res += v ? 1 : 0;
        }
        return res;
    }
};