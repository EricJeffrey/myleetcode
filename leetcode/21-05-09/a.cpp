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
    int maximumPopulation(vector<vector<int>> &logs) {
        int years[2051] = {};
        for (int i = 1950; i < 2050; i++) {
            for (auto &&vec : logs) {
                int a = vec[0], b = vec[1];
                if (i >= a && i < b)
                    years[i]++;
            }
        }
        int maxv = years[1950];
        int maxi = 1950;
        for (int i = 1950; i < 2050; i++) {
            if (years[i] > maxv) {
                maxi = i;
                maxv = years[i];
            }
        }
        return maxi;
    }
};

int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}
