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

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int h = (int)log2(n);
    int x = n - (1 << h) + 1;
    vector<vector<bool>> treeEven(h + 1);
    for (int i = 0; i < h; i++) {
        treeEven[i].resize(1 << i, true);
    }
    treeEven[h].resize(x, true);
    int u = 0;
    for (int i = h; i >= 0; i -= 2) {
        u += treeEven[i].size();
    }
    int v = 0;
    for (int i = h - 1; i >= 0; i -= 2) {
        v += treeEven[i].size();
    }
    int start = u > v ? h : h - 1;
    int oddcnt = 0;
    for (int i = start; i >= 0; i -= 2) {
        if (treeEven[i].size() + oddcnt >= (n + 1) / 2) {
            fill(treeEven[i].begin(), treeEven[i].begin() + (n + 1) / 2 - oddcnt, false);
            break;
        } else {
            fill(treeEven[i].begin(), treeEven[i].end(), false);
            oddcnt += treeEven[i].size();
        }
    }
    int eveni = 1, oddi = 0;
    // vector<int> res;
    int tmp = 0;
    for (auto &&vec : treeEven) {
        for (auto &&t : vec) {
            if (t) {
                tmp = 2 * eveni;
                cout << tmp << " ";
                eveni += 1;
            } else {
                tmp = 2 * oddi + 1;
                cout << tmp << " ";
                oddi += 1;
            }
            // res.push_back(tmp);
        }
    }
    // for (auto &&t : res) {
    //     if (t > n)
    //         cout << "------FAILED-----" << endl;
    // }

    return 0;
}
