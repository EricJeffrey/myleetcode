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

/*
   4
IIIDIDID
12354768

IIIDIIDD
123546987

IDIIDDDI

    t -1 -2 -3
xxxID D  D  _

DIDDI
215436

IIDDI
12

 */

class Solution {
public:
    string smallestNumber(string pattern) {
        set<int> s;
        for (int i = 1; i < 10; i++) {
            s.insert(i);
        }
        vector<int> res(pattern.size() + 1, 0);
        for (size_t i = 0; i < pattern.size();) {
            char ch = pattern[i];
            if (ch == 'I') {
                res[i] = *s.begin();
                s.erase(res[i]);
                i += 1;
            } else {
                int cnt = 1;
                while (i + cnt < pattern.size() && pattern[i + cnt] == 'D') {
                    cnt += 1;
                }
                int v = *s.begin() + cnt;
                for (int j = 0; j < cnt; j++) {
                    res[i + j] = v - j;
                    s.erase(res[i + j]);
                }
                res[i + cnt] = *s.begin();
                s.erase(res[i + cnt]);
                i = i + cnt + 1;
            }
        }
        if (res.back() == 0) {
            res.back() = *s.begin();
        }
        string ret(res.size(), '0');
        for (size_t i = 0; i < res.size(); i++) {
            ret[i] = res[i] + '0';
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().smallestNumber("IIIDIDID") << endl;
    cout << Solution().smallestNumber("IIIDIIDD") << endl;
    cout << Solution().smallestNumber("IDIIDDDI") << endl;
    cout << Solution().smallestNumber("DIDDI") << endl;
    cout << Solution().smallestNumber("IIDDI") << endl;
    return 0;
}
