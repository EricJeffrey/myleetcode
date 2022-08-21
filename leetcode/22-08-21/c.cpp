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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    struct T {
        int val;
        T *left, *right, *parent;
        T() : val(-1), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    int target = 0;
    T *nstart = nullptr;

    void dfs(TreeNode *root, T *newRoot) {
        newRoot->val = root->val;
        if (root->val == target) {
            nstart = newRoot;
        }
        T *nleft = nullptr;
        if (root->left != nullptr) {
            nleft = new T();
            nleft->parent = newRoot;
            dfs(root->left, nleft);
        }
        newRoot->left = nleft;
        T *nright = nullptr;
        if (root->right != nullptr) {
            nright = new T();
            nright->parent = newRoot;
            dfs(root->right, nright);
        }
        newRoot->right = nright;
    }

public:
    int amountOfTime(TreeNode *root, int start) {
        nstart = nullptr;
        target = start;
        T *newRoot = new T();
        dfs(root, newRoot);
        using pti = pair<T *, int>;
        queue<pti> q;
        q.push({nstart, 0});
        unordered_set<int> infected;
        infected.insert(start);
        int res = 0;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            res = p.second;
            infected.insert(p.first->val);
            auto putToQ = [&infected, &q](T *who, int v) {
                if (who != nullptr && infected.find(who->val) == infected.end()) {
                    q.push({who, v});
                }
            };
            putToQ(p.first->left, p.second + 1);
            putToQ(p.first->right, p.second + 1);
            putToQ(p.first->parent, p.second + 1);
        }
        return res;
    }
};