#include <algorithm>
#include <array>
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
    long long interchangeableRectangles(vector<vector<int>> &rectangles) {
        auto sssum = [](int v) { return (1ll + v) * v / 2; };
        unordered_map<double, int> ratescnt;
        for (auto &&v : rectangles) {
            ratescnt[v[0] / (1.0 * v[1])] += 1;
        }
        long long res = 0;
        for (auto &&p : ratescnt) {
            if (p.second > 1)
                res += sssum(p.second - 1);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> rectangles;
    rectangles = {{4, 8}, {3, 6}, {10, 20}, {15, 30}};
    cout << Solution().interchangeableRectangles(rectangles) << endl;
    return 0;
}
