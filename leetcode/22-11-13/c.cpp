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
public:
    void dfs(TreeNode *p, int layer, unordered_map<int, vector<int>> &layers) {
        if (p == nullptr) return;
        layers[layer].push_back(p->val);
        dfs(p->left, layer + 1, layers);
        dfs(p->right, layer + 1, layers);
    }
    int minimumOperations(TreeNode *root) {
        unordered_map<int, vector<int>> layers;
        dfs(root, 0, layers);
        int res = 0;
        unordered_map<int, int> rawPos;
        unordered_map<int, int> targetPos;
        for (auto &&p : layers) {
            vector<int> vec = p.second;
            sort(vec.begin(), vec.end());
            for (int i = 0; i < vec.size(); i++) {
                targetPos[vec[i]] = i;
                rawPos[p.second[i]] = i;
            }
            int tmpres = 0;
            for (size_t i = 0; i < vec.size(); i++) {
                int u = vec[i];
                if (vec[i] != p.second[i]) {
                    printf("DEBUG, layer: %d, u: %d, v: %d\n", p.first, p.second[i],
                           p.second[rawPos[u]]);
                    int posOfV = rawPos[u];
                    swap(p.second[i], p.second[posOfV]);
                    rawPos[p.second[i]] = i;
                    rawPos[p.second[posOfV]] = posOfV;
                    tmpres += 1;
                }
            }
            res += tmpres;
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    //
    return 0;
}
