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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNodes(ListNode *head) {
        vector<int> nodes;
        ListNode *p = head;
        while (p) {
            nodes.push_back(p->val);
            p = p->next;
        }
        stack<int> s;
        vector<int> valsToRes;
        for (int i = nodes.size() - 1; i >= 0; i--) {
            int u = nodes[i];
            while (!s.empty() && u >= s.top()) {
                s.pop();
            }
            if (s.empty()) {
                valsToRes.push_back(u);
            }
            s.push(u);
        }
        reverse(valsToRes.begin(), valsToRes.end());
        ListNode *nhead = new ListNode(0);
        p = nhead;
        for (auto &&v : valsToRes) {
            p->next = new ListNode(v);
            p = p->next;
        }
        return nhead->next;
    }
};