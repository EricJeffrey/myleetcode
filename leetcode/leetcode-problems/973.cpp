#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

// #define debug 1

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {

        nth_element(points.begin(), points.begin() + K - 1, points.end(), [](vector<int> &p, vector<int> &q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

int main(int argc, char const *argv[]) {
    vvi points = {{-5, 4}, {-3, 2}, {0, 1}, {-3, 7}, {-2, 0}, {-4, -6}, {0, -5}};
    int k = 6;
    Solution().kClosest(points, k);
    return 0;
}
