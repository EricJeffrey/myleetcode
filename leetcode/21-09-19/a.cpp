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
    int finalValueAfterOperations(vector<string> &operations) {
        int res = 0;
        for (auto &&v : operations) {
            if (v.find('+') != v.npos) {
                res += 1;
            } else {
                res -= 1;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) { return 0; }
