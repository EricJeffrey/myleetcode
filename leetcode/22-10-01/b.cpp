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


class LUPrefix {
    vector<unsigned long long> bs;

public:
    LUPrefix(int n) {
        bs.clear();
        bs.resize(n / 64 + (n % 64 > 0 ? 1 : 0), 0ull);
    }

    void upload(int video) {
        video -= 1;
        int which = video / 64;
        unsigned long long where = 1ull << (video % 64);
        bs[which] |= where;
    }

    int longest() {
        int res = 0;
        for (size_t i = 0; i < bs.size(); i++) {
            unsigned long long u = bs[i];
            cout << u << endl;
            if (u == 0xffffffffffffffff) {
                res += 64;
            } else {
                unsigned long long v = (u + 1ull) & ~u;
                if (v != 0) res += (int)log2(v);
                break;
            }
        }
        return res;
    }
};

int main() {
    LUPrefix p(40);
    cout << p.longest() << endl;
}

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */