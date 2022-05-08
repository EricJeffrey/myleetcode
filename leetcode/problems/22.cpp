#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
struct Temp {
  public:
    int step;
    int lbn, rbn;

    Temp(int s, int l, int r) : step(s), lbn(l), rbn(r) {}
};
class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        dfs(0, 0, n, "", res);
    }
    void dfs(int lbn, int rbn, int n, string s, vector<string> &res) {
        if (lbn == n && lbn == rbn)
            res.push_back(s);
        if (lbn < n)
            dfs(lbn + 1, rbn, n, s + "(", res);

        if (rbn < lbn)
            dfs(lbn, rbn + 1, n, s + ")", res);
    }
};

int main(int argc, char const *argv[]) {
    int n;
    while (cin >> n) {
        vector<string> res = Solution().generateParenthesis(n);
        for (auto &&s : res) {
            cout << s << endl;
        }
        cout << res.size() << endl;
    }
    return 0;
}
