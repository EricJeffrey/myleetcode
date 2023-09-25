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
    int minimumMoves(vector<vector<int>> &grid) {
        vector<pair<int, int>> froms, tos;
        for (int i = 0; i < 9; i++) {
            int x = i / 3, y = i % 3;
            int u = grid[x][y];
            if (u == 0)
                tos.push_back({x, y});
            else {
                while (u > 1) {
                    froms.push_back({x, y});
                    u -= 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < froms.size(); i++) {
            res += abs(froms[i].first - tos[i].first) + abs(froms[i].second - tos[i].second);
        }
        while (next_permutation(froms.begin(), froms.end())) {
            int tmpres = 0;
            for (int i = 0; i < froms.size(); i++) {
                tmpres += abs(froms[i].first - tos[i].first) + abs(froms[i].second - tos[i].second);
            }
            res = min(res, tmpres);
        }
        return res;
    }
};
int main(int argc, char const *argv[]) { return 0; }
