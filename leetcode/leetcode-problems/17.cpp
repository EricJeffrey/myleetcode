#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
  private:
    string num2str[10] = {"0",   "0",   "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    vector<int> xmx, xs, num2num = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
    int n;

  public:
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if (n <= 0)
            return res;
        return go(digits);
    }
    bool add1() {
        int i = n - 1;
        xs[i]++;
        while (i >= 0 && xs[i] >= xmx[i]) {
            xs[i--] = 0;
            i >= 0 ? xs[i]++ : i;
        }
        return i >= 0;
    }
    vector<string> go(string digits) {
        for (char ch : digits) {
            xmx.push_back(num2num[ch - '0']);
            xs.push_back(0);
        }
        while (1) {
            string tmpstr;
            for (int i = 0; i < n; i++)
                tmpstr.push_back(num2str[digits[i] - '0'][xs[i]]);
            res.push_back(tmpstr);
            if (!add1())
                break;
        }
        return res;
    }
};
int main(int argc, char const *argv[]) {
    string digits;
    digits = "23";
    vector<string> res = Solution().letterCombinations(digits);
    for (string s : res)
        cout << s << ',';
    return 0;
}
