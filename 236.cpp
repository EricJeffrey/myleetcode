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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        unordered_map<int, bool> mp;
        sPathOfTarget(root, p, q, mp);
        sPathOfTarget(root, p, q, mp);
        return sAncestor(root, p, q, mp);
    }
    bool sPathOfTarget(TreeNode *root, TreeNode *p, TreeNode *q, unordered_map<int, bool> &mp) {
        if (root == nullptr)
            return 0;
        if (root == p || root == q) {
            mp[root->val] = 1;
            if (mp[p->val] && mp[q->val])
                return 1;
        }
        bool res = sPathOfTarget(root->left, p, q, mp) || sPathOfTarget(root->right, p, q, mp);
        if (res)
            return mp[root->val] = 1;
        return 0;
    }
    TreeNode *sAncestor(TreeNode *root, TreeNode *p, TreeNode *q, unordered_map<int, bool> &mp) {
        if (root == p || root == q)
            return root;
        bool lval = root->left == nullptr ? 0 : mp[root->left->val];
        bool rval = root->right == nullptr? 0: mp[root->right->val];
        if (lval && rval)
            return root;
        return sAncestor((lval ? root->left : root->right), p, q, mp);
    }
};
int main(int argc, char const *argv[]) {
    TreeNode *p = new TreeNode(3);
    // p->left = new TreeNode(5);
    p->right = new TreeNode(1);
    // p->left->left = new TreeNode(6);
    p->right->left = new TreeNode(0);
    p->right->right = new TreeNode(8);
    cout << Solution().lowestCommonAncestor(p, p->right->right, p->right->left)->val;
    return 0;
}