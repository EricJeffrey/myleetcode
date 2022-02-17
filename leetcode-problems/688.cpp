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
    double knightProbability(int n, int k, int row, int column) {
        if (row >= n || column >= n)
            return 0;
        if (k == 0)
            return 1;
        typedef pair<int, int> point;
        vector<vector<vector<point>>> reach_graph(n, vector<vector<point>>(n));
        auto calc_reach_point = [](int r, int c, int nn) {
            vector<point> res;
            int nrs[8] = {r - 2, r - 2, r - 1, r - 1, r + 1, r + 1, r + 2, r + 2};
            int ncs[8] = {c - 1, c + 1, c - 2, c + 2, c - 2, c + 2, c - 1, c + 1};
            for (int i = 0; i < 8; i++) {
                int nr = nrs[i], nc = ncs[i];
                if (nr >= 0 && nc >= 0 && nr < nn && nc < nn)
                    res.push_back(make_pair(nr, nc));
            }
            return res;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                reach_graph[i][j] = calc_reach_point(i, j, n);
            }
        }
        map<point, double> point2prob;
        point2prob[make_pair(row, column)] = 1;
        int cnt = 1;
        for (; cnt <= k; cnt++) {
            map<point, double> nm;
            for (auto &&v : point2prob) {
                auto po = v.first;
                double prob = v.second;
                for (auto &&np : reach_graph[po.first][po.second]) {
                    if (nm.find(np) == nm.end())
                        nm[np] = 0;
                    nm[np] += prob * 0.125;
                }
            }
            point2prob = nm;
        }
        double res = 0;
        for (auto &&v : point2prob) {
            res += v.second;
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().knightProbability(3, 2, 0, 0) << endl;
    cout << Solution().knightProbability(1, 0, 0, 0) << endl;
    cout << Solution().knightProbability(1, 1, 0, 0) << endl;
    cout << Solution().knightProbability(25, 100, 12, 13) << endl;
    return 0;
}
