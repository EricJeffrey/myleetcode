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

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

const int maxn = 1e5 + 5;
int tree[4 * maxn] = {};
int lazy[4 * maxn] = {};
void buildTree(int l, int r, int k) {
    tree[k] = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1, lc = k << 1, rc = (k << 1) + 1;
    buildTree(l, mid, lc);
    buildTree(mid + 1, r, rc);
}
void pushdown(int l, int r, int k) {
    if (lazy[k] == 0)
        return;
    int mid = (l + r) >> 1, lc = k << 1, rc = (k << 1) + 1;
    if (lazy[k] == 1) {
        lazy[lc] = lazy[rc] = 1;
        tree[lc] = (mid - l + 1);
        tree[rc] = (r - mid);
    } else if (lazy[k] == -1) {
        lazy[lc] = lazy[rc] = -1;
        tree[lc] = tree[rc] = 0;
    }
    lazy[k] = 0;
}
void update(int ul, int ur, int v, int l, int r, int k) {
    if (ul <= l && ur >= r) {
        tree[k] = v * (r - l + 1);
        lazy[k] = (v == 1 ? 1 : -1);
        return;
    }
    if (ul > r || ur < l)
        return;
    pushdown(l, r, k);
    int mid = (l + r) >> 1, lc = k << 1, rc = (k << 1) + 1;
    update(ul, ur, v, l, mid, lc);
    update(ul, ur, v, mid + 1, r, rc);
    tree[k] = tree[lc] + tree[rc];
}
class Solution {
public:
    void dfs(TreeNode *p, vector<int> &nums) {
        if (p == nullptr)
            return;
        nums.push_back(p->val);
        dfs(p->left, nums);
        dfs(p->right, nums);
    }
    int getNumber(TreeNode *root, vector<vector<int>> &ops) {
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        vector<int> nums;
        nums.reserve(maxn);
        dfs(root, nums);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]] = i + 1;
        buildTree(1, n, 1);
        // printf("__DEBUG__\n");
        // for (int i = 0; i < 2 * n; i++) {
        //     printf("%2d, ", i);
        // }
        // printf("\n");
        // for (int i = 0; i < 2 * n; i++) {
        //     printf("%2d, ", tree[i]);
        // }
        // printf("\n");
        for (auto &&vec : ops) {
            int type = vec[0], x = vec[1], y = vec[2];
            x = mp[x], y = mp[y];
            // printf("__DEBUG__: %d %d %d\n", type, x, y);
            update(x, y, type, 1, n, 1);

            // printf("__DEBUG__\n");
            // for (int i = 0; i < 2 * n; i++) {
            //     printf("%2d, ", i);
            // }
            // printf("\n");
            // for (int i = 0; i < 2 * n; i++) {
            //     printf("%2d, ", tree[i]);
            // }
            // printf("\n");
        }
        return tree[1];
    }
};

int main(int argc, char const *argv[]) {
    TreeNode *head = new TreeNode(0);
    vector<int> tmp = {23, 4, 47, 2, 21, 35, 94, 0, 14, 22, 28, 36, 51, 100, 40, 49, 54, 83, 66, 85};
    TreeNode *p = head;
    for (size_t i = 1; i < tmp.size(); i++) {
        p->left = new TreeNode(tmp[i]);
        p = p->left;
    }
    vector<vector<int>> ops;
    ops = {{1, 0, 51}, {0, 2, 36}, {0, 2, 54}, {1, 35, 66}};
    cout << Solution().getNumber(head->left, ops) << endl;
    return 0;
}
