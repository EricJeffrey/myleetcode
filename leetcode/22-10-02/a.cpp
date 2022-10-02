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
    int commonFactors(int a, int b) {
        int res = 0;
        for (int i = 1; i <= min(a, b); i++) {
            if (a % i == 0 && b % i == 0) res += 1;
        }
        return res;
    }
};

int main(int argc, char const *argv[]) { return 0; }
