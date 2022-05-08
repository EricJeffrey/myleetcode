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

const size_t MAXN = 501;

vector<set<int>> splitgraph(int root, const vector<set<int>> &graph) {
    vector<set<int>> parts;
    vector<bool> visited(MAXN, false);
    visited[root] = true;
    auto mark = [&graph, &visited, &parts](int p, int sid) {
        queue<int> q;
        q.push(p);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            if (visited[u])
                continue;
            visited[u] = true;
            parts[sid].insert(u);
            for (auto &&v : graph[u])
                if (visited[v] == false)
                    q.push(v);
        }
    };
    int sid = 0;
    for (auto &&u : graph[root]) {
        if (visited[u])
            continue;
        parts.push_back({});
        mark(u, sid);
        sid += 1;
    }
    return parts;
}
int dfs(set<int> nodes, const vector<set<int>> &graph, bool bonmany = false) {
    size_t n = nodes.size();
    if (n == 1)
        return 1;
    vector<int> roots;
    for (auto &&node : nodes)
        if (graph[node].size() == n - 1)
            roots.push_back(node);
    int res = 0;
    for (auto &&root : roots) {
        auto parts = splitgraph(root, graph);

        vector<set<int>> ngraph = graph;
        for (auto &&u : graph[root])
            ngraph[u].erase(root);
        ngraph[root].clear();

        nodes.erase(root);
        int tmpres = 1;
        for (auto &&part : parts) {
            tmpres *= dfs(part, ngraph);
            if (tmpres == 0)
                break;
        }
        nodes.insert(root);

        res += tmpres;
        if (res > 1 && bonmany) {
            res = 2;
            break;
        }
    }
    return res;
}

// 超时，但是值得记录
class Solution {
public:
    int checkWays(vector<vector<int>> &pairs) {
        set<int> nodes;
        vector<set<int>> graph(MAXN);
        for (auto &&vec : pairs) {
            graph[vec[0]].insert(vec[1]);
            graph[vec[1]].insert(vec[0]);
            nodes.insert(vec[0]);
            nodes.insert(vec[1]);
        }
        int res = dfs(nodes, graph, true);
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> pairs;
    pairs = {{1, 2}, {1, 4}, {2, 3}, {2, 4}, {3, 4}, {4, 5},
             {4, 6}, {4, 7}, {5, 6}, {5, 7}, {6, 7}};
    cout << Solution().checkWays(pairs) << endl;
    return 0;
}
