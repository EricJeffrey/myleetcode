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

struct A;
struct B;
struct ListNode1 {
    ListNode1 *next;
    ListNode1 *prev;
    A *a;
    B *b;
};

void insert_after(ListNode1 *pos, ListNode1 *node) {
    node->prev = pos;
    node->next = pos->next;
    if (pos->next) {
        pos->next->prev = node;
    }
    pos->next = node;
}

void insert_before(ListNode1 *pos, ListNode1 *node) {
    if (pos->prev) {
        node->prev = pos->prev;
        node->next = pos;
        pos->prev->next = node;
        pos->prev = node;
    } else {
        node->prev = nullptr;
        node->next = pos;
        pos->prev = node;
    }
}

void delete_at(ListNode1 *pos) {
    if (pos->prev) {
        pos->prev->next = pos->next;
    }
    if (pos->next) {
        pos->next->prev = pos->prev;
    }
    pos->prev = pos->next = nullptr;
    pos->a = nullptr;
}

struct A {
    int nr_bs;
    int cnt;
    ListNode1 bhead, btail;
    ListNode1 node;
};
struct B {
    int key;
    int val;
    A *abox;
    ListNode1 node;
};
const int maxn = 1e5 + 1;

A *mallocnewa() {
    A *newa = (A *)malloc(sizeof(A));
    memset(newa, 0, sizeof(A));
    newa->nr_bs = 0;
    newa->cnt = 0;
    newa->bhead.next = &newa->btail;
    newa->btail.prev = &newa->bhead;
    newa->node.a = newa;
    return newa;
}

void insertBtoA(B *b, A *a) {
    insert_after(&a->bhead, &b->node);
    b->abox = a;
    a->nr_bs += 1;
}

class LFUCache {
public:
    B key2bs[maxn];
    ListNode1 ahead, atail;
    int nums;
    int capacity;

    LFUCache(int cap) {
        memset(key2bs, 0, sizeof(key2bs));
        for (int i = 0; i < maxn; i++) {
            key2bs[i].key = i;
            key2bs[i].node.b = &key2bs[i];
            key2bs[i].val = -1;
        }
        ahead.prev = atail.next = nullptr;
        ahead.next = &atail;
        atail.prev = &ahead;
        nums = 0;
        this->capacity = cap;
    }

    int get(int key) {
        // cout << "get    " << key << endl;
        B *b = &key2bs[key];
        A *cur_abox = b->abox;
        int res = b->val;
        if (res == -1) {
            return res;
        }

        delete_at(&b->node);
        // 最后再释放 abox
        cur_abox->nr_bs -= 1;

        if (cur_abox->node.prev == &ahead || cur_abox->node.prev->a->cnt != cur_abox->cnt + 1) {
            A *newa = mallocnewa();
            newa->cnt = cur_abox->cnt + 1;
            insert_before(&cur_abox->node, &newa->node);
        }
        A *preva = cur_abox->node.prev->a;
        insertBtoA(b, preva);

        if (cur_abox->nr_bs == 0) {
            delete_at(&cur_abox->node);
            free(cur_abox);
        }

        return res;
    }

    void put(int key, int value) {
        B *curb = &key2bs[key];
        if (curb->val == -1) {
            // 把cnt最小的移除
            if (nums >= capacity) {
                A *targeta = atail.prev->a;
                B *targetb = targeta->btail.prev->b;
                {
                    // cout << "before delete nr_bs: " << targeta->nr_bs << ", cnt: " << targeta->cnt << ", targeta: " << targeta << ", ahead: " << &ahead << endl;
                    // cout << "delete " << targetb->key << endl;
                    // 删除b
                    delete_at(&targetb->node);
                    targetb->val = -1;
                    nums -= 1;
                }
                targeta->nr_bs -= 1;
                if (targeta->nr_bs == 0) {
                    delete_at(&targeta->node);
                    free(targeta);
                }
            }

            /* add to head of A of cnt 1 */
            curb->val = value;
            if (atail.prev == &ahead || atail.prev->a->cnt > 1) {
                A *newa = mallocnewa();
                newa->cnt = 1;
                insert_before(&atail, &newa->node);
            }
            // cout << "insert " << key << endl;
            A *aofcnt1 = atail.prev->a;
            insertBtoA(curb, aofcnt1);
            nums += 1;
        } else {
            if (curb->val != value) {
                curb->val = value;
            }
            get(key);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char const *argv[]) {
    vector<string> cmds;
    vector<vector<int>> params;

    cmds = {"LFUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"};
    params = {{10},{10,13},{3,17},{6,11},{10,5},{9,10},{13},{2,19},{2},{3},{5,25},{8},{9,22},{5,5},{1,30},{11},{9,12},{7},{5},{8},{9},{4,30},{9,3},{9},{10},{10},{6,14},{3,1},{3},{10,11},{8},{2,14},{1},{5},{4},{11,4},{12,24},{5,18},{13},{7,23},{8},{12},{3,27},{2,12},{5},{2,9},{13,4},{8,18},{1,7},{6},{9,29},{8,21},{5},{6,30},{1,12},{10},{4,15},{7,22},{11,26},{8,17},{9,29},{5},{3,4},{11,30},{12},{4,29},{3},{9},{6},{3,4},{1},{10},{3,29},{10,28},{1,20},{11,13},{3},{3,12},{3,8},{10,9},{3,26},{8},{7},{5},{13,17},{2,27},{11,15},{12},{9,19},{2,15},{3,16},{1},{12,17},{9,1},{6,19},{4},{5},{5},{8,1},{11,7},{5,2},{9,28},{1},{2,2},{7,4},{4,22},{7,24},{9,26},{13,28},{11,26}};
    LFUCache *obj = new LFUCache(params[0][0]);
    for (int i = 1; i < params.size(); i++) {
        if (cmds[i] == "put") {
            printf("put %d\n", params[i][0]);
            fflush(stdout);
            obj->put(params[i][0], params[i][1]);
        } else {
            printf("get %d\n", params[i][0]);
            fflush(stdout);
            obj->get(params[i][0]);
        }
        for (ListNode1 *acurr = obj->ahead.next; acurr != &obj->atail; acurr = acurr->next) {
            printf("cnt:%d nr_bs:%d -> ", acurr->a->cnt, acurr->a->nr_bs);
            for (ListNode1 *bcurr = acurr->a->bhead.next; bcurr != &acurr->a->btail; bcurr = bcurr->next) {
                printf("(%2d:%2d) -> ", bcurr->b->key, bcurr->b->val);
            }
            printf("\n");
        }
        printf("----------\n");
    }
    return 0;
}
