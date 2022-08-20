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
    string shiftingLetters(string s, vector<vector<int>> &shifts) {
        vector<int> a(s.size() + 1, 0);
        for (auto &&vec : shifts) {
            int start = vec[0], end = vec[1];
            int v = (vec[2] == 0 ? -1 : 1);
            a[start] += v;
            a[end + 1] += -v;
        }
        for (size_t i = 1; i < a.size(); i++) {
            a[i] = a[i - 1] + a[i];
        }
        for (size_t i = 0; i < a.size(); i++) {
            a[i] = (a[i] % 26 + 26) % 26;
        }

        string res = s;
        for (size_t i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';
            index = (index + a[i]) % 26 + 'a';
            res[i] = index;
        }
        return res;
    }
};
