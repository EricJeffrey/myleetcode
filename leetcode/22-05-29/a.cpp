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
    int rearrangeCharacters(string s, string target) {
        int cnts[26] = {};
        int cntt[26] = {};
        for (auto &&c : s) {
            cnts[c - 'a'] += 1;
        }
        for (auto &&c : target) {
            cntt[c - 'a'] += 1;
        }
        int minV = INT32_MAX;
        for (int i = 0; i < 26; i++) {
            if (cntt[i] != 0) {
                if (cnts[i] == 0) {
                    minV = 0;
                    break;
                } else {
                    minV = min(minV, cnts[i] / cntt[i]);
                }
            }
        }
        return minV;
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().rearrangeCharacters("ilovecodingonleetcode", "code") << endl;
    cout << Solution().rearrangeCharacters("abcba", "abc") << endl;
    cout << Solution().rearrangeCharacters("abbaccaddaeea", "aaaaa") << endl;
    cout << Solution().rearrangeCharacters("aaaaabbbbbbbbbccccccccc", "aabbbbc") << endl;
    cout << Solution().rearrangeCharacters("abbaccaaeea", "aabcd") << endl;
    return 0;
}
