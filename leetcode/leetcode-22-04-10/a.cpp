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
    int largestInteger(int num) {
        vector<int> odds, evens;
        stack<bool> oddoreven;
        int x = num;
        while (x > 0) {
            int u = x % 10;
            if (u % 2 == 0)
                evens.push_back(u);
            else
                odds.push_back(u);
            oddoreven.push(x % 2 == 1);
            x = x / 10;
        }
        sort(odds.begin(), odds.end());
        sort(evens.begin(), evens.end());
        int res = 0;
        while (!oddoreven.empty()) {
            res *= 10;
            if (oddoreven.top()) {
                res += odds.back();
                odds.pop_back();
            } else {
                res += evens.back();
                evens.pop_back();
            }
            oddoreven.pop();
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().largestInteger(65875) << endl;
    cout << Solution().largestInteger(1234) << endl;
    return 0;
}
