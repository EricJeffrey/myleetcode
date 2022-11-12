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
    const int maxn = 1e5 + 5;
    vector<vector<int>> graph;
    vector<int> timeBobHere;

    int dfsBob(int who, int bobPos, vector<bool> &visited) {
        int bobWhen = -1;
        if (bobPos == who) bobWhen = 0;
        visited[who] = true;
        for (auto &&v : graph[who]) {
            if (!visited[v]) {
                int tmp = dfsBob(v, bobPos, visited);
                if (tmp != -1) {
                    bobWhen = tmp + 1;
                }
            }
        }
        return timeBobHere[who] = bobWhen;
    }
    int dfsAlice(int who, int t, int score, vector<bool> &visited, const vector<int> &amount) {
        visited[who] = true;
        if (timeBobHere[who] == -1) {
            score += amount[who];
        } else if (timeBobHere[who] < t) {
            // no need update score
        } else if (timeBobHere[who] == t) {
            score += amount[who] / 2;
        } else {
            score += amount[who];
        }
        int res = INT_MIN;
        int leafCnt = 0;
        for (auto &&v : graph[who]) {
            if (!visited[v]) {
                int tmp = dfsAlice(v, t + 1, score, visited, amount);
                res = max(res, tmp);
                leafCnt += 1;
            }
        }
        if (leafCnt == 0) {
            return score;
        }
        return res;
    }

    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount) {
        graph.clear();
        graph.resize(maxn);
        timeBobHere.clear();
        timeBobHere.resize(maxn, -1);
        for (auto &&vec : edges) {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        vector<bool> visited(maxn, false);
        dfsBob(0, bob, visited);
        fill(visited.begin(), visited.end(), false);
        int res = dfsAlice(0, 0, 0, visited, amount);
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> edges = {{0, 1}};
    int bob = 1;
    vector<int> amount = {-7280, 2350};
    // cout << Solution().mostProfitablePath(edges, bob, amount) << endl;
    edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    bob = 3;
    amount = {-2, 4, 2, -4, 6};
    cout << Solution().mostProfitablePath(edges, bob, amount) << endl;
    return 0;
}
