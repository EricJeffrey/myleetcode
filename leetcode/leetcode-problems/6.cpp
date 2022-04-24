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
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string res;
        for (int i = 0; i < numRows; i++) {
            for (int k = 0;; k++) {
                int tmp = k * (2 * numRows - 2) + numRows - 1;
                int v = (numRows - 1 - i);
                if (tmp - v >= s.size())
                    break;
                res += s[tmp - v];
                if (i == 0 || i == numRows - 1)
                    continue;
                if (tmp + v >= s.size())
                    break;
                res += s[tmp + v];
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().convert("PAYPALISHIRING", 3) << endl;
    cout << Solution().convert("PAYPALISHIRING", 4) << endl;
    cout << Solution().convert("PAYPALISHIRING", 1000) << endl;
    cout << Solution().convert("P", 1) << endl;

    return 0;
}
