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
    int maxSizeSlices(vector<int> &slices) {
        const int sz = (int)slices.size();
        vector<vector<int>> dp1(sz, vector<int>(sz / 3 + 1, 0));
        dp1[0][1] = slices[0];
        dp1[1][1] = max(slices[0], slices[1]);
        for (int i = 2; i < sz - 1; i++) {
            dp1[i][1] = max(dp1[i - 1][1], slices[i]);
            for (int j = 1; j <= i && j <= sz / 3; j++) {
                dp1[i][j] = max(dp1[i - 1][j], dp1[i - 2][j - 1] + slices[i]);
            }
        }
        vector<vector<int>> dp2(sz, vector<int>(sz / 3 + 1, 0));
        dp2[1][1] = slices[1];
        for (int i = 2; i < sz; i++) {
            dp2[i][1] = max(dp2[i - 1][1], slices[i]);
            for (int j = 1; j <= i && j <= sz / 3; j++) {
                dp2[i][j] = max(dp2[i - 1][j], dp2[i - 2][j - 1] + slices[i]);
            }
        }
        return max(dp1[sz - 2][sz / 3], dp2[sz - 1][sz / 3]);
    }
};

int main(int argc, char const *argv[]) {
    auto testout = [](vector<int> slices) {
        cout << Solution().maxSizeSlices(slices) << endl;
    };
    testout({9, 5, 1, 7, 8, 4, 4, 5, 5, 8, 7, 7});
    testout({8, 9, 8, 6, 1, 1});
    testout({4, 1, 2, 5, 8, 3, 1, 9, 7});
    testout({1, 2, 3, 4, 5, 6});
    return 0;
}
