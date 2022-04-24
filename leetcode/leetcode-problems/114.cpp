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
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    void flatten(TreeNode *root) { root = f(root); }
    TreeNode *f(TreeNode *p) {
        if (p == nullptr || (p->left == nullptr && p->right == nullptr))
            return p;
        TreeNode *le = f(p->left), *ri = f(p->right), *tmp;
        p->left = nullptr;
        if (le == nullptr)
            return p;
        tmp = le;
        while (tmp->right != nullptr)
            tmp = tmp->right;
        tmp->right = ri;
        p->right = le;
        return p;
    }
};

int main(int argc, char const *argv[]) {
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(5);
    p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(4);
    p->right->right = new TreeNode(6);
    Solution().flatten(p);
    return 0;
}
