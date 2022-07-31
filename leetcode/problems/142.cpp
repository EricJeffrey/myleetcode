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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !(head->next))
            return nullptr;
        ListNode *p, *q;
        p = head->next, q = head->next->next;
        while (p != q) {
            if (!p || !q || !(q->next))
                return nullptr;
            p = p->next, q = q->next->next;
        }
        p = head;
        while (p != q)
            p = p->next, q = q->next;
        return p;
    }
};