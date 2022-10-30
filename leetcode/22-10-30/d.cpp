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
    unordered_map<int, int> heights;

public:
    int dfs(TreeNode *root) {
        if (root == nullptr) return 0;
        int h = max(dfs(root->left), dfs(root->right));
        return heights[root->val] = h + 1;
    }
    void dfs2(TreeNode *root, int depth, int resH, unordered_map<int, int> &tmpRes) {
        if (root == nullptr) return;
        tmpRes[root->val] = resH;
        dfs2(root->left, depth + 1,
             max(resH, (root->right ? heights[root->right->val] : 0) + depth), tmpRes);
        dfs2(root->right, depth + 1, max(resH, (root->left ? heights[root->left->val] : 0) + depth),
             tmpRes);
    }
    vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
        heights.clear();
        dfs(root);
        unordered_map<int, int> tmpRes;
        dfs2(root, 0, 0, tmpRes);
        vector<int> answers;
        for (auto &&v : queries) {
            answers.push_back(tmpRes[v]);
        }
        return answers;
    }
};

int main(int argc, char const *argv[]) { return 0; }
