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

/*

a1 a2 a3... -> ap, abuff => 最小power, 穿过后得到的加成
b1 b2 b3... -> bp, bbuff
c1 c2 c3... -> cp, cbuff

3
1
1 1000000000
4
2 100000000 99999999
4 1 2 32 2
3 35 12 22
6 33 1 2 22 33 1
3
1 1
1 2

 */

struct Tmp {
    int64_t start;
    int64_t buff;
    int64_t end;
    Tmp(int64_t s, int64_t b) : start(s), buff(b), end(s + b) {}
    bool operator<(const Tmp &t) const {
        if (start != t.start)
            return start < t.start;
        return end < t.end;
    }
};

int main(int argc, char const *argv[]) {
    //
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n);
        vector<Tmp> segs;
        segs.reserve(n);
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            a[i].resize(k, 0);
            int curmax = 0;
            for (int j = 0; j < k; j++) {
                cin >> a[i][j];
                // curmax = max(curmax, a[i][j]);
                curmax = max(curmax, a[i][j] + 1 - j);
            }
            if (a[i][0] == curmax)
                curmax += 1;
            segs.push_back({curmax, k});
        }
        sort(segs.begin(), segs.end());
        vector<Tmp> nsegs = {segs[0]};
        nsegs.reserve(n);
        for (size_t i = 1; i < segs.size(); i++) {
            if (segs[i].start <= nsegs.back().end) {
                Tmp tmpseg = {nsegs.back().start, segs[i].buff + nsegs.back().buff};
                nsegs.back() = tmpseg;
            } else {
                nsegs.push_back(segs[i]);
            }
        }
        int64_t res = nsegs[0].start;
        for (size_t i = 1; i < nsegs.size(); i++) {
            res += nsegs[i].start - nsegs[i - 1].end;
        }
        cout << res << endl;
    }
    return 0;
}
