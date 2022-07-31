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
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *solve(vector<ListNode *> &a) {
        set<int> s;
        for (size_t i = 0; i < a.size(); i++) {
            ListNode *p = a[i];
            while (p != nullptr) {
                s.insert(p->val);
                p = p->next;
            }
        }
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        for (auto &&v : s) {
            p->next = new ListNode(v);
            p = p->next;
        }
        return head->next;
    }
};

int main(int argc, char const *argv[]) {
    vector<ListNode *> a;
    return 0;
}
