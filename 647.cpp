#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
class Solution {
  public:
    int countSubstrings(string s) {
        const int sz = s.size();
        int res = sz;
        for (int i = 1; i < sz - 1; i++) {
            int pre = i - 1, nxt = i + 1;
            while (pre >= 0 && nxt < sz) {
                if (s[pre] == s[nxt])
                    res++;
                else
                    break;
                pre -= 1;
                nxt += 1;
            }
        }
        for (int i = 1; i < sz; i++) {
            if (s[i] == s[i - 1]) {
                res++;
                int pre = i - 2, nxt = i + 1;
                while (pre >= 0 && nxt < sz) {
                    if (s[pre] == s[nxt])
                        res++;
                    else
                        break;
                    pre -= 1;
                    nxt += 1;
                }
            }
        }
        return res;
    }
};
int main() {
    string s = "abda";
    cout << Solution().countSubstrings(s) << endl;
    return 0;
}