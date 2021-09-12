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
#include <vector>
using namespace std;

const int maxn = 12;
void dfs(deque<int> indexlist, const string &s, vector<bitset<maxn>> &bslist) {
    bitset<maxn> bs;
    for (auto &&v : indexlist)
        bs.set(v);
    bslist.push_back(bs);
    int ledge = indexlist.front(), redge = indexlist.back();
    ledge -= 1;
    redge += 1;
    for (int lx = ledge; lx >= 0; lx--) {
        char ch = s[lx];
        int rx = redge;
        while (rx < s.size()) {
            if (s[rx] == ch) {
                deque<int> tmpindexlist = indexlist;
                tmpindexlist.push_front(lx);
                tmpindexlist.push_back(rx);
                dfs(tmpindexlist, s, bslist);
            }
            rx++;
        }
    }
}

class Solution {
public:
    int maxProduct(string s) {
        const int n = s.size();
        vector<bitset<maxn>> bslist;
        for (int i = 0; i < n; i++) {
            dfs({i}, s, bslist);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    dfs({i, j}, s, bslist);
            }
        }
        sort(bslist.begin(), bslist.end(),
             [](const bitset<maxn> &u, const bitset<maxn> &v) { return u.count() < v.count(); });
        int res = 1;
        for (int i = bslist.size() - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if ((bslist[i] & bslist[j]) == 0) {
                    res = max(res, (int)(bslist[i].count() * bslist[j].count()));
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    string s;
    s = "leetcodecom";
    cout << Solution().maxProduct(s) << endl;
    s = "bb";
    cout << Solution().maxProduct(s) << endl;
    s = "accbcaxxcxx";
    cout << Solution().maxProduct(s) << endl;
    s = "hhawhwhh";
    cout << Solution().maxProduct(s) << endl;
    return 0;
}
