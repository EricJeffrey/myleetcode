#include <algorithm>
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
#include <vector>
using namespace std;

struct Node {
    int timeTake, index;
    Node() {}
    Node(int t, int i) : timeTake(t), index(i) {}
    bool operator<(const Node &t) const { return timeTake > t.timeTake; }
};
struct Branch {
    int to, weight;
    Branch() {}
    Branch(int t, int w) : to(t), weight(w) {}
};
typedef vector<vector<Branch>> Graph;

class Solution {
public:
    Graph buildGraph(const vector<vector<int>> &edges, int N) {
        Graph res(N + 1);
        for (auto &&edge : edges)
            res[edge[0]].push_back(Branch(edge[1], edge[2]));
        return res;
    }
    int networkDelayTime(vector<vector<int>> &times, int N, int K) {
        Graph graph = buildGraph(times, N);
        vector<bool> visited(N + 1, false);
        priority_queue<Node> q;
        q.push(Node(0, K));
        int maxTime = 0;
        while (!q.empty()) {
            Node u = q.top();
            q.pop();
            if (visited[u.index])
                continue;
            maxTime = max(maxTime, u.timeTake);
            visited[u.index] = true;
            for (auto &&v : graph[u.index])
                q.push(Node(u.timeTake + v.weight, v.to));
        }
        for (int i = 1; i <= N; i++)
            if (!visited[i]) return -1;
        return maxTime;
    }
};
int main(int argc, char const *argv[]) {
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 4, 1},
        {2, 3, 1},
        {2, 3, 5},
        {3, 3, 0},
        {3, 2, 5},
        {3, 4, 1},
    };
    int n = 4, k = 2;
    cout << Solution().networkDelayTime(times, n, k) << endl;
    return 0;
}
