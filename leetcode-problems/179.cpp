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
bool cmp(int u, int v) {
    string usvs = to_string(u) + to_string(v);
    string vsus = to_string(v) + to_string(u);
    return usvs < vsus;
}

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res;
        for (int i = nums.size() - 1; i >= 0; i--)
            res += to_string(nums[i]);
        int i = 0;
        while (i < res.size() && res[i] == '0')
            i++;
        if (i < res.size())
            res = res.substr(i);
        else
            res = "0";
        return res;
    }
};
int main(int argc, char const *argv[]) { return 0; }
