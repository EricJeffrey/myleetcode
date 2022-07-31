#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    string decodeString(string s) {
        stack<char> box;
        for (int i = 0; i < (int)s.size(); i++) {
            const char ch = s[i];
            if (ch != ']') {
                box.push(ch);
            } else {
                string tmps;
                for (; box.top() != '['; box.pop())
                    tmps += box.top();
                box.pop();
                string tmpnum;
                for (; !box.empty() && isdigit(box.top()) != 0; box.pop())
                    tmpnum.insert(tmpnum.begin(), box.top());
                int tmpn = atoi(tmpnum.c_str());
                for (int j = 0; j < tmpn; j++)
                    for (int k = tmps.size() - 1; k >= 0; k--)
                        box.push(tmps[k]);
            }
        }
        string res;
        for (; !box.empty(); box.pop())
            res.insert(res.begin(), box.top());
        return res;
    }
};
int main(int argc, char const *argv[]) {
    string s = "3[a3[css]]2[bc]";
    cout << Solution().decodeString(s) << endl;
    return 0;
}
