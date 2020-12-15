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
/* Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

typedef pair<ListNode *, ListNode *> PLL;
class Solution {
  public:
    ListNode *sortList(ListNode *head) {
        if (!head || !(head->next))
            return head;
        int n = 0, i = 1;
        ListNode *p = head, *tail, *lastTail;
        while (p)
            p = p->next, n++;
        for (i = 1; i <= n; i <<= 1) {
            lastTail = p = head;
            head = tail = nullptr;
            while (p) {
                for (int j = 1; j <= (i << 1) && lastTail; j++)
                    lastTail = lastTail->next;
                PLL tmp = merge(p, i);
                if (!head) {
                    head = tmp.first;
                    tail = tmp.second;
                    tail->next = nullptr;
                    p = lastTail;
                    continue;
                }
                tail->next = tmp.first;
                tail = tmp.second;
                if (!tail)
                    break;
                p = lastTail;
            }
        }
        return head;
    }
    PLL merge(ListNode *p, int n) {
        if (!p)
            return PLL(nullptr, nullptr);
        ListNode *q = p, *head = nullptr;
        int len = 1;
        while (q->next && len <= n)
            q = q->next, len++;
        if (len <= n)
            return PLL(p, q);
        ListNode *reshead, *restail;
        int i = 0, j = 0;
        p->val < q->val ? (reshead = p, p = p->next, i++) : (reshead = q, q = q->next, j++);
        head = restail = reshead;
        for (; i < n || (j < n && q);) {
            if (i == n) {
                head->next = q;
                q = q->next;
                j++;
            } else if (j == n || !q) {
                head->next = p;
                p = p->next;
                i++;
            } else {
                p->val < q->val ? (head->next = p, p = p->next, i++) : (head->next = q, q = q->next, j++);
            }
            head = head->next;
            restail = head ? head : restail;
        }
        restail->next = nullptr;
        return PLL(reshead, restail);
    }
};

int main(int argc, char const *argv[]) {
    ListNode *head = new ListNode(4);
    ListNode *p = head;
    p->next = new ListNode(3), p = p->next;
    p->next = new ListNode(2), p = p->next;
    p->next = new ListNode(1), p = p->next;
    // p->next = new ListNode(2), p = p->next;
    // p->next = new ListNode(4), p = p->next;
    // p->next = new ListNode(6), p = p->next;
    ListNode *res = Solution().sortList(head);
    while (res)
        cout << res->val << ", ", res = res->next;
    return 0;
}
