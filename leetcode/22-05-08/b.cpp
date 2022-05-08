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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef pair<int, int> pii;
class Solution {
    pii dfs(TreeNode *root, int &res) {
        if (root == nullptr)
            return {0, 0};
        int sum = root->val, cnt = 1;
        pii lc = dfs(root->left, res), rc = dfs(root->right, res);
        sum += lc.first + rc.first;
        cnt += lc.second + rc.second;
        if (root->val == sum / cnt)
            res += 1;
        return {sum, cnt};
    }

public:
    int averageOfSubtree(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int res = 0;
        dfs(root, res);
        return res;
    }
};

int main(int argc, char const *argv[]) {

    cout << Solution().averageOfSubtree(nullptr) << endl;
    return 0;
}
