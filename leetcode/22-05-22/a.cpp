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
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for (auto &&c : s) {
            if (letter == c)
                cnt += 1;
        }
        return (int)floor(cnt * 1.0 / s.size() * 100);
    }
};