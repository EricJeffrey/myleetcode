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
    int minScore(int n, vector<vector<int>> &roads) {
        vector<int> score(n + 1, INT32_MAX);
        vector<bool> visited(n + 1, false);
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto &&vec : roads) {
            int u = vec[0], v = vec[1], s = vec[2];
            graph[u].push_back(make_pair(v, s));
            graph[v].push_back(make_pair(u, s));
        }
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            auto u = q.front();
            visited[u] = true;
            q.pop();
            for (auto &&p : graph[u]) {
                if (!visited[p.first]) {
                    score[p.first] = min(min(score[u], score[p.first]), p.second);
                    q.push(p.first);
                }
            }
        }
        int res = score[n];
        if (res == INT32_MAX) return -1;
        for (auto &&s : score) {
            if (s != INT32_MAX) {
                res = min(res, s);
            }
        }

        return res;
    }
};