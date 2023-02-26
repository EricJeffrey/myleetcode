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
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        multiset<int> s;
        for (int i = nums.size() / 2; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        int res = 0;
        for (int i = 0; i < nums.size() / 2; i++) {
            int u = nums[i];
            auto it = s.lower_bound(u * 2);
            if (it != s.end()) {
                res += 2;
                s.erase(it);
            } else {
                break;
            }
        }
        return res;
    }
};
