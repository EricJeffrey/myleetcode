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
    int largestPerimeter(vector<int> &A) {
        if (A.size() < 3)
            return 0;
        sort(A.begin(), A.end(), [](int x, int y) { return x > y; });
        int x = A[0], y = A[1], z = A[2];
        auto check = [](int x, int y, int z) { return (x + y) > z && (x + z) > y && (y + z) > x; };
        for (size_t i = 2; i < A.size(); i++) {
            z = A[i];
            if (check(x, y, z)) return x + y + z;
            x = y;
            y = z;
        }
        return 0;
    }
};
int main(int argc, char const *argv[]) {

    return 0;
}
