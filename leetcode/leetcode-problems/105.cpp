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
/**
 * Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
typedef vector<int>::iterator VIIT;
class Solution {
  private:
    vector<int> pre, in;
    unordered_map<int, int> mp;

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        const int n = preorder.size();
        if (n <= 0)
            return nullptr;
        pre = preorder, in = inorder;
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        return bTree2(0, 0, n);
        // return bTree(preorder.begin(), inorder.begin(), preorder.size());
    }
    TreeNode *bTree2(int prepos, int inpos, int len) {
        if (len <= 1)
            return len == 1 ? new TreeNode(pre[prepos]) : nullptr;
        int prefir = pre[prepos];
        int tmppos = mp[prefir];
        int tmplen = tmppos - inpos;
        TreeNode *p = new TreeNode(prefir);
        p->left = bTree2(prepos + 1, inpos, tmplen);
        tmplen += 1;
        p->right = bTree2(prepos + tmplen, inpos + tmplen, len - tmplen);
        return p;
    }
    // 每次遍历找根，递归求子树
    TreeNode *bTree(VIIT preit, VIIT init, int len) {
        if (len <= 0)
            return nullptr;
        int tmppos = 0, v = *preit;
        while (*(init + tmppos) != v)
            tmppos++;
        TreeNode *p = new TreeNode(v);
        p->left = bTree(preit + 1, init, tmppos);
        p->right =
            bTree(preit + tmppos + 1, init + tmppos + 1, len - tmppos - 1);
        return p;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> pre, in;
    pre = {0, 1, 3, 4, 5, 2, 6, 9, 7, 8};
    in = {3, 1, 5, 4, 0, 6, 9, 2, 8, 7};
    cout << Solution().buildTree(pre, in);
    return 0;
}

// abdefcgjhi
// dbfeagjcih
