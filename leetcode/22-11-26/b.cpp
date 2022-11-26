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
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid) {
        vector<int> onesRow, onesCol, zerosRow, zerosCol;
        onesRow.resize(grid.size(), 0);
        zerosRow.resize(grid.size(), 0);
        onesCol.resize(grid[0].size(), 0);
        zerosCol.resize(grid[0].size(), 0);
        vector<vector<int>> diff(grid.size(), vector<int>(grid[0].size()));
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    zerosRow[i] += 1;
                    zerosCol[j] += 1;
                } else {
                    onesRow[i] += 1;
                    onesCol[j] += 1;
                }
            }
        }
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[i].size(); j++) {
                diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }
        return diff;
    }
};