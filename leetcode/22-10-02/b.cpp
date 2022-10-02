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
    int maxSum(vector<vector<int>> &grid) {
        int res = 0;
        for (int i = 2; i < grid.size(); i++) {
            for (int j = 2; j < grid[i].size(); j++) {
                int tmpres = 0;
                for (int ii = 0; ii < 3; ii++) {
                    for (int jj = 0; jj < 3; jj++) {
                        tmpres += grid[i - ii][j - jj];
                    }
                }
                tmpres -= grid[i - 1][j] + grid[i - 1][j - 2];
                res = max(res, tmpres);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) { return 0; }
