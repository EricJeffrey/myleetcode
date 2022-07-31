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
    string minimizeResult(string expression) {
        size_t where = expression.find('+');
        auto eval = [&expression, where](size_t i, size_t j) {
            int leftm = 1;
            if (i != 0)
                leftm = stoi(expression.substr(0, i));
            int mim = stoi(expression.substr(i, where - i)) +
                      stoi(expression.substr(where + 1, j + 1 - where - 1));
            int rightm = 1;
            if (j != expression.size() - 1)
                rightm = stoi(expression.substr(j + 1, expression.size() - j - 1));
            return leftm * mim * rightm;
        };
        int maxv = INT32_MAX;
        size_t maxi = 0, maxj = expression.size() - 1;
        // add at left of i, right of j
        for (size_t i = 0; i <= where - 1; i++) {
            for (size_t j = where + 1; j < expression.size(); j++) {
                int tmp = eval(i, j);
                // cout << "DEBUG: " << tmp << endl;
                if (tmp < maxv) {
                    maxi = i;
                    maxj = j;
                    maxv = tmp;
                }
            }
        }
        string res = expression;
        res.insert(res.begin() + maxj + 1, ')');
        res.insert(res.begin() + maxi,  '(');
        return res;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().minimizeResult("247+38") << endl;
    cout << Solution().minimizeResult("12+34") << endl;
    cout << Solution().minimizeResult("999+999") << endl;
    return 0;
}
