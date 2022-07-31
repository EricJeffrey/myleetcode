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

struct Tmp {
    int left, right;
    bool operator<(const Tmp &t) const { return right < t.left; };
};

class CountIntervals {
    set<Tmp> dset1;
    int cnt;

public:
    CountIntervals() : cnt(0) {}

    void add(int left, int right) {
        Tmp t1 = Tmp{left, right};
        auto it1 = dset1.lower_bound(t1);
        if (it1 == dset1.end()) {
            cnt += right - left + 1;
            dset1.insert(t1);
            return;
        }
        int oldcnt = 0;
        int resl = left, resr = right;
        auto nit1 = it1;
        while (nit1 != dset1.end()) {
            if (nit1->left > right)
                break;
            oldcnt += nit1->right - nit1->left + 1;
            resl = min(resl, nit1->left);
            resr = max(resr, nit1->right);
            nit1++;
        }
        cnt = cnt - oldcnt + resr - resl + 1;
        dset1.erase(it1, nit1);
        dset1.insert(Tmp{resl, resr});
    }

    int count() { return cnt; }
};