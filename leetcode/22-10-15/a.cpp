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
    int countTime(string time) {
        auto tmpToStr = [](int x) {
            if (x < 10) return "0" + to_string(x);
            return to_string(x);
        };
        int res = 0;
        for (int i = 0; i <= 23; i++) {
            for (int j = 0; j < 60; j++) {
                string tmp = tmpToStr(i) + ':' + tmpToStr(j);
                bool ok = true;
                for (size_t k = 0; k < 5; k++) {
                    if (time[k] != '?' && time[k] != tmp[k]) {
                        ok = false;
                    }
                }
                if (ok) res += 1;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().countTime("?5:00") << endl;
    cout << Solution().countTime("0?:0?") << endl;
    cout << Solution().countTime("??:??") << endl;
    return 0;
}
