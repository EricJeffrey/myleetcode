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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode(0);
        int carry = l1->val + l2->val;
        carry >= 10 ? (res->val = carry - 10, carry = 1) : (res->val = carry, carry = 0);
        ListNode *p = res;
        for (l1 = l1->next, l2 = l2->next; l1 || l2;) {
            ListNode *q = new ListNode(0);
            int tmp = 0;
            if (!l1) {
                tmp = l2->val;
                l2 = l2->next;
            } else if (!l2) {
                tmp = l1->val;
                l1 = l1->next;
            } else {
                tmp = l1->val + l2->val;
                l2 = l2->next;
                l1 = l1->next;
            }
            tmp += carry;
            tmp >= 10 ? (q->val = tmp - 10, carry = 1) : (q->val = tmp, carry = 0);
            p->next = q;
            p = q;
        }
        if (carry)
            p->next = new ListNode(carry);
        return res;
    }
};
int main(int argc, char const *argv[]) { return 0; }
