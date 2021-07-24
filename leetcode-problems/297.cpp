#include <algorithm>
#include <array>
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// inline int serializeInt(int x) { return x + 1000; }
// inline int deSerializeInt(int x) { return x - 1000; }

struct NodeHelper {
    int16_t value;
    uint16_t father;

    inline void setLeft() { father |= 0x8000; }
    inline uint16_t readFa() { return father & 0x7fff; }
    inline bool isLeftChild() { return (father & 0x8000) >> 15; }
};

NodeHelper makeNodeHelper(int value, int father, bool leftChild) {
    NodeHelper res{(int16_t)value, (uint16_t)father};
    if (leftChild)
        res.setLeft();
    return res;
}

class Codec {
    void dfs(TreeNode *root, int father, bool leftChild, vector<NodeHelper> &nodes) {
        if (root == nullptr)
            return;
        nodes.push_back(makeNodeHelper(root->val, father, leftChild));
        const int meIndex = (int)(nodes.size()) - 1;
        if (root->left != nullptr)
            dfs(root->left, meIndex, true, nodes);
        if (root->right != nullptr)
            dfs(root->right, meIndex, false, nodes);
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr)
            return "";
        vector<NodeHelper> nodes;
        dfs(root, 0, false, nodes);
        const size_t totalNumberBytes = (nodes.size() << 2);
        string res(totalNumberBytes, 0);
        memcpy(res.data(), nodes.data(), totalNumberBytes);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.empty())
            return nullptr;
        const size_t sz = data.size();
        vector<TreeNode *> treeNodes(sz >> 2, nullptr);
        NodeHelper *tmpNodeHelper = reinterpret_cast<NodeHelper *>(data.data());
        treeNodes[0] = new TreeNode(tmpNodeHelper->value);
        for (size_t i = 4; i < sz; i += 4) {
            tmpNodeHelper = reinterpret_cast<NodeHelper *>(data.data() + i);
            TreeNode *tmpTreeNode = new TreeNode(tmpNodeHelper->value);
            treeNodes[i >> 2] = tmpTreeNode;
            uint16_t tmpFa = tmpNodeHelper->readFa();
            if (tmpNodeHelper->isLeftChild())
                treeNodes[tmpFa]->left = tmpTreeNode;
            else
                treeNodes[tmpFa]->right = tmpTreeNode;
        }
        return treeNodes[0];
    }
};

int main(int argc, char const *argv[]) {
    // Your Codec object will be instantiated and called as such:
    // Codec ser, deser;
    // TreeNode* ans = deser.deserialize(ser.serialize(root));
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    Codec ser;
    string res = ser.serialize(nullptr);
    for (size_t i = 0; i < res.size(); i += 2) {
        printf("%02x%02x ", res[i + 1], res[i]);
    }
    printf("\n");
    Codec deser;
    TreeNode *resroot = deser.deserialize(res);
    printf("res root,left,right: %d %d %d\n", resroot->val, resroot->left->val,
           resroot->right->val);

    // char ch[4] = {};
    // NodeHelper helper = {0x1125, 0x636};
    // helper.setLeft();
    // memcpy(ch, &helper, 4);
    // for (size_t i = 0; i < 4; i++) {
    //     printf("%x ", ch[i]);
    // }
    // NodeHelper res = *(reinterpret_cast<NodeHelper *>(ch));
    // printf("res: %x %x\n", res.value, res.father);
    return 0;
}
