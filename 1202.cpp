#include <algorithm>
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

class Solution {
public:
    int findFa(int x, vector<int> &fa) {
        return fa[x] == x ? x : fa[x] = findFa(fa[x], fa);
    }

    void unite(int x, int y, vector<int> &fa) {
        int fax = findFa(x, fa), fay = findFa(y, fa);
        fa[fay] = fax;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        const int sz = (int)s.size();
        vector<int> fa(sz, -1);
        for (int i = 0; i < sz; i++)
            fa[i] = i;
        for (auto &&p : pairs)
            unite(p[0], p[1], fa);
        unordered_map<int, vector<int>> fa2index;
        for (int i = 0; i < sz; i++)
            fa2index[findFa(i, fa)].push_back(i);
        for (auto &&p : fa2index) {
            vector<char> indexcp(p.second.size());
            for (size_t i = 0; i < p.second.size(); i++)
                indexcp[i] = s[p.second[i]];
            sort(indexcp.begin(), indexcp.end());
            for (size_t i = 0; i < indexcp.size(); i++)
                s[p.second[i]] = indexcp[i];
        }
        return s;
    }
};

int main(int argc, char const *argv[]) {
    auto testout = [](string s, vector<vector<int>> pairs) {
        cout << Solution().smallestStringWithSwaps(s, pairs) << endl;
    };
    testout("dcab", {{0, 3}, {1, 2}});
    testout("dcab", {{0, 3}, {1, 2}, {0, 2}});
    testout("cba", {{0, 1}, {1, 2}});
    return 0;
}
