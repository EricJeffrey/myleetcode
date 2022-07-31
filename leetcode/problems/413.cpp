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
    int numberOfArithmeticSlices(vector<int> &A) {
        const int sz = (int)A.size();
        if (sz < 3)
            return 0;
        auto resOfN = [](int n) {
            return (n - 1) * (n - 2) / 2;
        };
        int res = 0;
        int i = 2, j = 0;
        while (i < sz) {
            while (i < sz && A[i] - A[i - 1] == A[i - 1] - A[i - 2])
                i++;
            if (i - j >= 3) {
                res += resOfN(i - j);
                j = i - 2;
            } else { // i did not move
                j = i - 1;
                i++;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    auto testout = [](vector<int> a) {
        cout << Solution().numberOfArithmeticSlices(a) << endl;
    };
    testout({1, 2, 3, 4});
    testout({1, 2, 3, 4, 5});
    testout({1, 2, 3, 5, 7, 9, 11, 22, 3, -16, -35});
    return 0;
}
