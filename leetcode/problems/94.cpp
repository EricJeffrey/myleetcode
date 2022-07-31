#include <algorithm>
#include <cstdio>
#include <cstdlib>
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        go(root, res);
        return res;
    }
    void go(TreeNode *t, vector<int> &res) {
        if (t == nullptr)
            return;
        go(t->left, res);
        res.push_back(t->val);
        go(t->right, res);
    }
};

int main(int argc, char const *argv[]) { return 0; }