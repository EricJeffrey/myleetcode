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
    int maxDistance(vector<int> &nums1, vector<int> &nums2) {
        int res = 0;
        int j = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int u = nums1[i];
            while (j < nums2.size() && nums2[j] >= u) {
                j += 1;
            }
            res = max(res, j - i - 1);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) { return 0; }
