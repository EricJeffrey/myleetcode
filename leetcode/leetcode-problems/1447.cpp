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

class Solution {
    vector<bool> a[101];

public:
    vector<string> simplifiedFractions(int n) {
        if (a[0].empty()) {
            for (int i = 0; i < 101; i++) {
                a[i].resize(101, true);
            }
            for (int i = 2; i < 101; i++) {
                for (int j = i; j < 101; j += i) {
                    for (int k = i; k < 101; k += i)
                        a[j][k] = false;
                }
            }
        }
        vector<string> res;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[i][j])
                    res.push_back(to_string(i) + "/" + to_string(j));
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    auto s = Solution();
    for (int n = 2; n <= 100; n++) {
        auto res = s.simplifiedFractions(n);
        for (auto &&v : res) {
            cout << v << ',';
        }
        cout << endl;
    }
    return 0;
}
