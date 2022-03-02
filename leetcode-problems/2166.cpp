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

class Bitset {
public:
    vector<uint64_t> values;
    int size;
    int cnt;
    bool flipped;

    Bitset(int size) {
        values.resize(size / 64 + (size % 64 != 0 ? 1 : 0), 0);
        this->size = size;
        flipped = false;
        cnt = 0;
    }

    void set_1(int index, int target, bool one) {
        uint64_t v = 1;
        v = (v << (63 - target));
        if (one)
            values[index] |= v;
        else
            values[index] &= ~v;
    }

    void fix(int idx) {
        int index = idx / 64;
        int target = idx % 64;
        uint64_t v = 1;
        v = (v << (63 - target));
        if ((flipped == false && ((values[index] & v)) == 0) ||
            (flipped == true && (values[index] & v) != 0)) {
            cnt += 1;
            if (flipped)
                values[index] &= ~v;
            else
                values[index] |= v;
        }
    }

    void unfix(int idx) {
        int index = idx / 64;
        int target = idx % 64;
        uint64_t v = 1;
        v = (v << (63 - target));
        if ((flipped == false && ((values[index] & v) != 0)) ||
            (flipped == true && ((values[index] & v) == 0))) {
            cnt -= 1;
            if (flipped)
                values[index] |= v;
            else
                values[index] &= ~v;
        }
    }

    void flip() { flipped = !flipped, cnt = size - cnt; }

    bool all() { return cnt == size; }

    bool one() { return cnt > 0; }

    int count() { return cnt; }

    string toString() {
        string res;
        for (size_t i = 0; i < values.size(); i++) {
            uint64_t v = values[i];
            if (flipped)
                v = ~v;
            if (size % 64 != 0 && i == values.size() - 1)
                v &= ~((uint64_t(1) << (64 - size % 64)) - 1);
            values[i] = v;
            string tmp;
            for (int j = 0; j < 64; j++) {
                tmp.push_back('0' + (v & 1));
                v >>= 1;
            }
            reverse(tmp.begin(), tmp.end());
            if (size % 64 != 0 && i == values.size() - 1)
                tmp = tmp.substr(0, size % 64);
            res += tmp;
        }
        flipped = false;
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Bitset bs(5 );
    cout << bs.toString() << endl;
    bs.fix(3);
    bs.fix(1);
    cout << bs.count() << endl;  // 2 
    bs.flip();
    cout << bs.count() << endl; // 3
    cout << bs.all() << endl; // 0
    bs.unfix(0);
    cout << bs.count() << endl; // 2
    bs.flip();
    cout << bs.count() << endl; // 3
    cout << bs.one() << endl; // 1
    bs.unfix(0);
    cout << bs.count() << endl;  // 2
    cout << bs.toString() << endl;

    return 0;
}
