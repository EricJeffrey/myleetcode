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
typedef vector<int> VI;
inline int char2int(char ch) {
    int res = ch - 'A';
    return res >= 26 ? res -= 6 : res;
};
struct Node {
    int val = 0;
    Node *t[52] = {};
    Node(){};
};
class Trie {
  public:
    Node *root;
    Trie() { root = new Node(); }
    void insert(string word) {
        const int n = word.size();
        if (n <= 0)
            return;
        int chi = char2int(word[0]);
        Node *p = root->t[chi] == nullptr ? (root->t[chi] = new Node()) : root->t[chi];
        for (int i = 0; i < n - 1; i++) {
            p->val == -1 ? p->val = 0 : 0;
            chi = char2int(word[i + 1]);
            p = p->t[chi] == nullptr ? p->t[chi] = new Node() : p->t[chi];
        }
        p->val == -1 ? p->val = 1 : p->val += 1;
    }
};
class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        const int n = s.size();
        if (wordDict.size() <= 0)
            return false;
        Trie *tree = new Trie();
        for (string tmps : wordDict)
            tree->insert(tmps);
        vector<int> sofdp[n + 1];
        for (int i = 0; i < n + 1; i++)
            sofdp[i] = vector<int>();
        for (int i = 0; i < n; i++)
            update(s, i, sofdp, tree);
        bool dp[n + 1] = {1};
        for (int i = 1; i <= n; i++) {
            for (int v : sofdp[i - 1]) {
                dp[i] = dp[i] || dp[v];
                if (dp[i] == 1)
                    break;
            }
        }
        return dp[n] == 1;
    }
    void update(string &s, int start, vector<int> sofdp[], Trie *tree) {
        const int n = s.size();
        if (start >= n)
            return;
        Node *p = tree->root;
        for (int i = start; i < n; i++) {
            int chi = char2int(s[i]);
            if (!p || !(p->t[chi]) || p->t[chi]->val == -1)
                break;
            if (p->t[chi]->val == 1)
                sofdp[i].push_back(start);
            p = p->t[chi];
        }
    }
};

int main(int argc, char const *argv[]) {
    vector<string> dict;
    string s;
    dict = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    cout << Solution().wordBreak(s, dict);
    return 0;
}

/*
sofdp[i] = 以 i 结尾的 word 的起点位置集合

dp[i] = 前 i个数是否能拼出来
    dp[0] = 0
    dp[i] = dp[k1] || dp[k2] ... k in sofdp[i]
*/
