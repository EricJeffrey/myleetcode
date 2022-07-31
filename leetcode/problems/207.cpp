#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
class Solution {
  public:
    bool cFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        if (prerequisites.size() <= 1)
            return true;
        vector<int> g[numCourses];
        int inDegree[numCourses] = {};
        for (PII tmppair : prerequisites) {
            if (tmppair.first == tmppair.second)
                return false;
            g[tmppair.second].push_back(tmppair.first);
            inDegree[tmppair.first]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u])
                if (--inDegree[v] == 0)
                    q.push(v);
        }
        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] != 0)
                return false;
        return true;
    }
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        if (prerequisites.size() <= 1)
            return true;
        vector<int> g[numCourses];
        bool inDegOrVis[numCourses] = {}, vis[numCourses] = {};
        for (PII tmppair : prerequisites) {
            if (tmppair.first == tmppair.second)
                return false;
            g[tmppair.second].push_back(tmppair.first);
            inDegOrVis[tmppair.first] = 1;
        }
        memset(inDegOrVis, 0, sizeof(bool) * numCourses);
        for (int i = 0; i < numCourses; i++) {
            if (vis[i])
                continue;
            if (!dfs(i, g, inDegOrVis, vis))
                return false;
        }
        return true;
    }
    bool dfs(int u, vector<int> g[], bool visited[], bool vis[]) {
        vis[u] = visited[u] = 1;
        bool res = true;
        for (int v : g[u]) {
            if (!res || visited[v]) {
                res = false;
                break;
            } else {
                res = res && dfs(v, g, visited, vis);
            }
        }
        visited[u] = 0;
        return res;
    }
};
int main(int argc, char const *argv[]) {
    int n, m;
    vector<PII> edges;
    while (cin >> n >> m) {
        edges.clear();
        for (int i = 0; i < m; i++) {
            PII edge;
            cin >> edge.first >> edge.second;
            edges.push_back(edge);
        }
        cout << Solution().canFinish(n, edges) << endl;
    }
    return 0;
}
/**
3 2
1 0
2 0

1 1
1 0

2 2
1 0
0 1

5 6
1 0
2 0
1 2
1 3
4 1
3 4

5 3
1 0
2 0
1 2

*/
