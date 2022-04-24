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
    int minSpeedOnTime(vector<int> &dist, double hour) {
        auto calcTimeNeed = [&dist](int x) {
            double timeneed = 0;
            for (size_t i = 0; i < dist.size(); i++) {
                auto v = dist[i];
                if (i != dist.size() - 1)
                    timeneed += ceil(v * 1.0 / x);
                else
                    timeneed += v * 1.0 / x;
            }
            return timeneed;
        };
        int l = 1, r = 1e7;
        while (l < r) {
            int mid = (l + r) >> 1;
            double timeneed = calcTimeNeed(mid);
            if (timeneed > hour) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (calcTimeNeed(l) > hour)
            return -1;
        return l;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> dist;
    double hour;
    dist = {1, 3, 2};
    hour = 2.7;
    cout << Solution().minSpeedOnTime(dist, hour) << endl;
    return 0;
}
