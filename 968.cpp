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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef vector<long long> NodeDP;
class Solution {
public:
    NodeDP dfs(TreeNode *p) {
        if (p == nullptr)
            return {INT_MAX, 0, 0};
        auto resl = dfs(p->left);
        auto resr = dfs(p->right);
        NodeDP res(3, INT_MAX);
        res[0] = 1 + *min_element(resl.begin(), resl.end()) + *min_element(resr.begin(), resr.end());
        res[1] = min(min(resl[0], resl[1]) + resr[0], min(resr[0], resr[1]) + resl[0]);
        res[2] = min(resl[0], resl[1]) + min(resr[0], resr[1]);
        return res;
    }
    int minCameraCover(TreeNode *root) {
        auto res = dfs(root);
        return min(res[0], res[1]);
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}
