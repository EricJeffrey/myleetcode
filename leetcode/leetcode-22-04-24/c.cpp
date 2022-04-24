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
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points) {
        int hmax = 100;
        vector<vector<int>> h2ls(hmax + 1, vector<int>());
        for (auto &&vec : rectangles) {
            int l = vec[0], h = vec[1];
            h2ls[h].push_back(l);
        }
        vector<vector<int>> y2xset(hmax + 1, vector<int>());
        multiset<int> tmpset;
        for (int hi = hmax; hi >= 1; hi--) {
            for (auto &&v : h2ls[hi]) {
                tmpset.insert(v);
            }
            y2xset[hi].reserve(tmpset.size());
            y2xset[hi] = vector<int>(tmpset.begin(), tmpset.end());
        }
        vector<int> res(points.size(), 0);
        for (size_t i = 0; i < points.size(); i++) {
            const auto &p = points[i];
            int x = p[0], y = p[1];
            auto it = lower_bound(y2xset[y].begin(), y2xset[y].end(), x);
            res[i] = y2xset[y].size() - distance(y2xset[y].begin(), it);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> rec, points;
    rec = {{1, 2}, {2, 3}, {2, 5}};
    points = {{2, 1}, {1, 4}};
    auto res = Solution().countRectangles(rec, points);
    for (auto &&v : res) {
        cout << v << ' ';
    }
    cout << endl;
    return 0;
}
