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
    long long dividePlayers(vector<int> &skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int v = skill[0] + skill.back();
        long long res = skill[0] * skill.back();
        for (int i = 1; i < n / 2; i++) {
            long long u = skill[i] + skill[n - 1 - i];
            if (u != v) {
                return -1;
            }
            res += skill[i] * skill[n - 1 - i];
        }
        return res;
    }
};