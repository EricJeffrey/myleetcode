#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TNode {
    int val;
    pair<int, int> robValPair;
    TNode *left, *right;
    TNode(int x) {
        this->val = x;
        this->left = this->right = nullptr;
        this->robValPair = make_pair(-1, -1);
    }
};

class Solution {
  private:
    map<int, pair<int, int>> dp;
    int dfs(TreeNode *p, bool canRob, int k) {
        if (p == nullptr)
            return 0;
        if (canRob && dp[k].first != -1)
            return dp[k].first;
        if (!canRob && dp[k].second != -1)
            return dp[k].second;
        int res = 0, lc = k << 1, rc = k << 1 | 1;
        if (canRob) {
            int rv = dfs(p->left, false, lc) + dfs(p->right, false, rc);
            res = max(rv + p->val, res);
        }
        res = max(dfs(p->left, true, lc) + dfs(p->right, true, rc), res);
        canRob ? dp[k].first = res : dp[k].second = res;
        return res;
    }
    void getTreeSz(TreeNode *p, int k) {
        if (p == nullptr)
            return;
        dp[k] = make_pair(-1, -1);
        getTreeSz(p->left, k << 1);
        getTreeSz(p->right, k << 1 | 1);
    }

    int dfs2(TNode *p, bool canRob) {
        if (p == nullptr)
            return 0;
        if (canRob && p->robValPair.first != -1)
            return p->robValPair.first;
        if (!canRob && p->robValPair.second != -1)
            return p->robValPair.second;
        int res = 0;
        if (canRob) {
            int rv = dfs2(p->left, false) + dfs2(p->right, false);
            res = max(rv + p->val, res);
        }
        res = max(dfs2(p->left, true) + dfs2(p->right, true), res);
        canRob ? p->robValPair.first = res : p->robValPair.second = res;
        return res;
    }
    void cpTree(TreeNode *p, TNode *q) {
        if (p == nullptr)
            return;
        q->val = p->val;
        if (p->left != nullptr) {
            q->left = new TNode(0);
            cpTree(p->left, q->left);
        }
        if (p->right != nullptr) {
            q->right = new TNode(0);
            cpTree(p->right, q->right);
        }
    }

  public:
    int rob(TreeNode *root) {
        getTreeSz(root, 1);
        return dfs(root, true, 1);
    }
    int rob2(TreeNode *root) {
        TNode *q = new TNode(0);
        cpTree(root, q);
        return dfs2(q, true);
    }
};

int main(int argc, char const *argv[]) {
    TreeNode *root = new TreeNode(3);
    TreeNode *p = root;
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    // p->left->left = new TreeNode(1);
    p->left->right = new TreeNode(3);
    p->right->right = new TreeNode(1);
    cout << Solution().rob2(root) << endl;
    return 0;
}
