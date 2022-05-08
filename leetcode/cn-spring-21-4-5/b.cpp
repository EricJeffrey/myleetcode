#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        xPos += 1;
        yPos += 1;
        int level = min(min(xPos, num - xPos + 1), min(yPos, num - yPos + 1));
        int t = level;
        if (t > 9) {
            t = t % 9;
            if (t == 0)
                t = 9;
        }
        t = t - 1;
        int start = (int)(((long long)t) * 4ll * (((long long)num) - t) % 9) + 1;
        long long dis = 0;
        long long k = num - 2ll * level + 2;
        if (xPos == level) {
            dis = yPos - level;
        } else if (xPos == num - level + 1) {
            dis = 2ll * k - 1 + (num - level + 1 - yPos) - 1;
        } else if (yPos == level) {
            dis = (num - level + 1) - xPos + 3ll * k - 2 - 1;
        } else if (yPos == num - level + 1) {
            dis = k + xPos - level - 1;
        }
        int res = (start + dis) % 9;
        if (res == 0)
            res = 9;
        return res;
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().orchestraLayout(1000000000, 5555555, 33333) << endl;
    return 0;
}
