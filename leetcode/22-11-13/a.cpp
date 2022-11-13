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
    vector<double> convertTemperature(double celsius) {
        vector<double> res;
        res.push_back(celsius + 273.15);
        res.push_back(celsius * 1.80 + 32);
        return res;
    }
};

int main(int argc, char const *argv[]) {
    //
    return 0;
}
