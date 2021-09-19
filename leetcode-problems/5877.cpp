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

class DetectSquares {
public:
    vector<vector<int>> cntofp;
    set<pair<int, int>> pset;

    DetectSquares() : cntofp(1001, vector<int>(1001, 0)) {}

    void add(vector<int> point) {
        cntofp[point[0]][point[1]] += 1;
        pset.insert({point[0], point[1]});
    }
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int res = 0;
        for (auto &&p : pset) {
            if (abs(p.first - x) == abs(p.second - y) && p.first != x) {
                res += cntofp[p.first][y] * cntofp[x][p.second] * cntofp[p.first][p.second];
            }
        }
        return res;
    }
};