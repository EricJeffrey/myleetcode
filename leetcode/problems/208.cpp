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
struct Node {
    int val;
    Node *t[26];
    Node() {
        val = 0;
        memset(t, 0, sizeof(t));
    };
};

class Trie {
  private:
    Node *root;

  public:
    Trie() { root = new Node(); }

    void insert(string word) {
        const int n = word.size();
        if (n <= 0)
            return;
        int chi = word[0] - 'a';
        Node *p = root->t[chi] == nullptr ? (root->t[chi] = new Node()) : root->t[chi];
        for (int i = 0; i < n - 1; i++) {
            p->val == -1 ? p->val = 0 : 0;
            chi = word[i + 1] - 'a';
            p = p->t[chi] == nullptr ? p->t[chi] = new Node() : p->t[chi];
        }
        p->val == -1 ? p->val = 1 : p->val += 1;
    }

    bool search(string word) {
        const int n = word.size();
        if (n <= 0)
            return false;
        Node *p = root->t[word[0] - 'a'];
        for (int i = 0; i < n - 1; i++) {
            if (p == nullptr || p->val == -1)
                return false;
            p = p->t[word[i + 1] - 'a'];
        }
        return p != nullptr && p->val > 0;
    }

    bool startsWith(string prefix) {
        const int n = prefix.size();
        if (n <= 0)
            return false;
        Node *p = root->t[prefix[0] - 'a'];
        for (int i = 0; i < n - 1; i++) {
            if (p == nullptr || p->val == -1)
                return false;
            p = p->t[prefix[i + 1] - 'a'];
        }
        return p != nullptr && p->val >= 0;
    }
};
int main(int argc, char const *argv[]) {
    Trie *trie = new Trie();

    trie->insert("apple");
    cout << trie->search("apple");   // returns true
    cout << trie->search("app");     // returns false
    cout << trie->startsWith("app"); // returns true
    trie->insert("app");
    cout << trie->search("app"); // returns true
    return 0;
}
