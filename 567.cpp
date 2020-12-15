#include <algorithm>
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
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        int cntOfLetters[26] = {};
        for (auto &&ch : s1)
            cntOfLetters[ch - 'a']++;
        int tmpCntOfLetters[26] = {};
        int cntLeft = (int)s1.size();
        int i = 0, j = 0;

        while (j < (int)s2.size()) {
            while (j < (int)s2.size() && tmpCntOfLetters[s2[j] - 'a'] < cntOfLetters[s2[j] - 'a']) {
                tmpCntOfLetters[s2[j] - 'a']++;
                cntLeft--;
                j++;
            }
            if (cntLeft == 0)
                return true;
            if (j == (int)s2.size())
                return false;
            if (cntOfLetters[s2[j] - 'a'] == 0) { // move i here
                while (i <= j) {
                    if (tmpCntOfLetters[s2[i] - 'a'] > 0) {
                        tmpCntOfLetters[s2[i] - 'a']--;
                        cntLeft++;
                    }
                    i++;
                }
                j++;
            } else { //
                tmpCntOfLetters[s2[i] - 'a']--;
                cntLeft++;
                i++;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    auto testout = [](string s1, string s2) {
        cout << Solution().checkInclusion(s1, s2) << endl;
    };
    testout("acct", "sxsodjoigtsdfccasddcaccatsdf");
    testout("ab", "eidbaooo");
    testout("ab", "eidboaoo");
    testout("hliimmu", "tvjrebdpgavfqlkcfuivkhasumimhliwozcyzgvfvfdbpjnzuxaowoboppazjzrhpvwpksodombqdqyelcbgnhmgienwyphfzil");

    return 0;
}
