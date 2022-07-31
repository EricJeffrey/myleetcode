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

struct ListNode {
    int val;
    ListNode *next, *prev;
};

struct ListNode *oddEvenList(struct ListNode *head) {
    ListNode *oddhead = new ListNode();
    ListNode *evenhead = new ListNode();
    ListNode *oddp = oddhead, *evenp = evenhead;
    int index = 1;
    ListNode *p = head;
    while (p != nullptr) {
        ListNode *target = (index % 2 == 0 ? evenp : oddp);
        ListNode *next = p->next;
        p->next = nullptr;
        target->next = p;
        (index % 2 == 0 ? evenp : oddp) = p;
        p = next;
        index += 1;
    }
    ListNode *eventodel = evenhead;
    ListNode *oddtodel = oddhead;
    evenhead = evenhead->next;
    oddhead = oddhead->next;
    delete eventodel;
    delete oddtodel;
    oddp->next = evenhead;
    return oddhead;
}

int main(int argc, char const *argv[]) {
    ListNode *p1, *p2, *p3, *p4, *p5, *p6;
    p1 = new ListNode();
    p2 = new ListNode();
    p3 = new ListNode();
    p4 = new ListNode();
    p5 = new ListNode();
    p6 = new ListNode();
    p1->val = 1;
    p2->val = 4;
    p3->val = 6;
    p4->val = 3;
    p5->val = 7;
    p6->val = 9;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    auto *p = oddEvenList(p1);
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
