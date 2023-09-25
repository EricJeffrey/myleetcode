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
    bool check(int x) {
        string xs = to_string(x);
        if (xs.size() % 2 != 0) {
            return false;
        }
        int n = xs.size();
        int leftsum = 0;
        int rightsum = 0;
        for (int i = 0; i < n / 2; i++) {
            leftsum += xs[i] - '0';
            rightsum += xs[n - 1 - i] - '0';
        }
        return leftsum == rightsum;
    }
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int i = low; i <= high; i++) {
            if (check(i)) {
                res += 1;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    //
    return 0;
}
