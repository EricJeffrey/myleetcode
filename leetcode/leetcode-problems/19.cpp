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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *who = head, *p = head;
        for (int i = 1; i <= n; i++)
            p = p->next;
        if (!p)
            return head->next;
        while (p && p->next)
            p = p->next, who = who->next;
        who->next = who->next->next;
        return head;
    }
};
int main(int argc, char const *argv[]) { return 0; }
