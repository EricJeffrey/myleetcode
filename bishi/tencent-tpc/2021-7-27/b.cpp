#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> cards(k);
        for (int i = 0; i < k; i++) {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                cards[i].push_back(x);
            }
        }
        vector<vector<int>> graph(n + 1);
        vector<int> degrees(n + 1, 0);
        for (auto &&vec : cards) {
            for (int i = 1; i < vec.size(); i++) {
                degrees[vec[i]] += 1;
                graph[vec[i - 1]].push_back(vec[i]);
            }
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (degrees[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cnt += 1;
            if (graph[u].size() > 0) {
                int v = graph[u][0];
                degrees[v] -= 1;
                if (degrees[v] == 0)
                    q.push(v);
            }
            if (graph[u].size() > 1) {
                int v = graph[u][1];
                degrees[v] -= 1;
                if (degrees[v] == 0)
                    q.push(v);
            }
        }
        if (cnt % 2 == 0)
            cout << "Nacho";
        else
            cout << "Kelly";
        cout << endl;
    }
    return 0;
}
