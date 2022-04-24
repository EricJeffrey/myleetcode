
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
    vector<int> pancakeSort(vector<int> &arr) {
        vector<int> res;
        int n = arr.size();
        int p = n - 1;
        while (p >= 0) {
            int which = min_element(arr.begin(), arr.begin() + p + 1) - arr.begin();
            if (which != p) {
                reverse(arr.begin(), arr.begin() + which + 1);
                res.push_back(which + 1);
                reverse(arr.begin(), arr.begin() + p + 1);
                res.push_back(p + 1);
            }
            p -= 1;
        }
        res.push_back(n);
        return res;
    }
};
