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

8387421

1-5位 9 + 9*9 + 9*9*8 + ...
1023456789

第一位是 1~7 7 * 9 * 8 * 7 * 6 ...
第一位是8，第二位是 0~2 1*3*8*7*...
第一位是8，第二位是3，第三位是0,1,2,4,5,6,7 7*7*...
第一位是8，第二位是3，第三位是8

 */

static vector<int> table;

class Solution {
public:
    // calc: from*(from-1)*(from-2)*...*(from-len+1)
    int mulOf(int from, int len) {
        static vector<int> prefix;
        if (prefix.empty()) {
            prefix.push_back(0);
            prefix.push_back(1);
            for (int i = 2; i < 10; i++) {
                prefix.push_back(prefix.back() * i);
            }
        }
        return prefix[from] / prefix[from - len];
    }
    int countSpecialNumbers(int n) {
        if (n <= 9) {
            return n;
        }
        if (table.empty()) {
            table.push_back(0);
            table.push_back(9);
            for (int i = 0; i < 8; i++) {
                table.push_back(table.back() * (9 - i));
            }
        }

        const string ns = to_string(n);
        int res = 0;
        // 累加前几位
        for (int i = 1; i < ns.size(); i++) {
            res += table[i];
        }
        // 特判第0位
        int firstOne = ns[0] - '0';
        res += (firstOne - 1) * mulOf(9, ns.size() - 1);
        // 计算之后每一位
        set<int> visited;
        visited.insert(firstOne);
        bool hasDup = false;
        for (size_t i = 1; i < ns.size(); i++) {
            int cur = ns[i] - '0';
            int avaCnt = 0;
            for (int k = 0; k < cur; k++) {
                if (visited.find(k) == visited.end())
                    avaCnt += 1;
            }
            res += avaCnt * mulOf(10 - i - 1, ns.size() - i - 1);
            if (visited.find(cur) != visited.end()) {
                hasDup = true;
                break;
            }
            visited.insert(cur);
        }
        if (!hasDup)
            res += 1;
        return res;
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().countSpecialNumbers(20) << endl;
    cout << Solution().countSpecialNumbers(5) << endl;
    cout << Solution().countSpecialNumbers(135) << endl;
    cout << Solution().countSpecialNumbers(834582) << endl;
    return 0;
}
