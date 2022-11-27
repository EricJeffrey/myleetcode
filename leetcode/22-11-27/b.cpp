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
    int appendCharacters(string s, string t) {
        size_t lastPos = 0;
        size_t count = 0;
        for (int i = 0; i < t.size(); i++) {
            char ch = t[i];
            auto pos = s.find(ch, lastPos);
            if (pos == s.npos) {
                break;
            } else {
                count += 1;
                lastPos = pos + 1;
            }
        }
        return t.size() - count;
    }
};