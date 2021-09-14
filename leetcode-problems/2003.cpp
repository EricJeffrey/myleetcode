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

void dfs(int x, int childnotvisit, const vector<int> &nums, const vector<vector<int>> &graph, vector<bool> &occured) {
    occured[nums[x]] = true;
    for (auto &&v : graph[x]) {
        if (childnotvisit == -1 || v != childnotvisit)
            dfs(v, -1, nums, graph, occured);
    }
}

class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int> &parents, vector<int> &nums) {
        const int n = parents.size();
        vector<vector<int>> graph(n);
        for (int i = 1; i < n; i++) {
            graph[parents[i]].push_back(i);
        }
        int nodeof1 = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                nodeof1 = i;
        }
        vector<int> ans(n, 1);
        if (nodeof1 == -1)
            return ans;
        queue<int> q;
        q.push(nodeof1);
        vector<bool> occured(1e5 + 2, false);
        int lastchild = -1;
        int curmin = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == -1)
                break;
            dfs(u, lastchild, nums, graph, occured);
            while (occured[curmin])
                curmin++;
            ans[u] = curmin;
            q.push(parents[u]);
            lastchild = u;
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> parents, nums;
    parents = {-1, 0, 0, 2}, nums = {1, 2, 3, 4};
    for (auto &&v : Solution().smallestMissingValueSubtree(parents, nums))
        cout << v << ' ';
    cout << endl;
    parents = {-1, 0, 1, 0, 3, 3}, nums = {5, 4, 6, 2, 1, 3};
    for (auto &&v : Solution().smallestMissingValueSubtree(parents, nums))
        cout << v << ' ';
    cout << endl;
    parents = {-1, 2, 3, 0, 2, 4, 1}, nums = {2, 3, 4, 5, 6, 7, 8};
    for (auto &&v : Solution().smallestMissingValueSubtree(parents, nums))
        cout << v << ' ';
    cout << endl;
    return 0;
}
