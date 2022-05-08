#include <algorithm>
#include <array>
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
    int minSwaps(string s) {
        if (s.size() == 0)
            return 0;
        int numOf1 = 0;
        int numOf0 = 0;
        for (auto &&c : s) {
            if (c == '0')
                numOf0++;
            else
                numOf1++;
        }
        if (abs(numOf0 - numOf1) > 1)
            return -1;
        int res = s.size();
        if (numOf0 > numOf1) {
            int v = 0;
            for (size_t i = 0; i < s.size(); i++) {
                char ch = (i & 1 ? '1' : '0');
                if (s[i] != ch)
                    v++;
            }
            res = min(v, res);
        } else if (numOf0 == numOf1) {
            int v = 0;
            for (size_t i = 0; i < s.size(); i++) {
                char ch = (i & 1 ? '1' : '0');
                if (s[i] != ch)
                    v++;
            }
            res = min(v, res);
            v = 0;
            for (size_t i = 0; i < s.size(); i++) {
                char ch = (i & 1 ? '0' : '1');
                if (ch != s[i])
                    v++;
            }
            res = min(v, res);
        } else {
            int v = 0;
            for (size_t i = 0; i < s.size(); i++) {
                char ch = (i & 1 ? '0' : '1');
                if (ch != s[i])
                    v++;
            }
            res = min(v, res);
        }
        return res >> 1;
    }
};

int main(int argc, char const *argv[]) {
    string s;
    s = "100011001";
    cout << Solution().minSwaps(s) << endl;
    s = "111000";
    cout << Solution().minSwaps(s) << endl;
    s = "010";
    cout << Solution().minSwaps(s) << endl;
    s = "1110";
    cout << Solution().minSwaps(s) << endl;
    s = "01110000111";
    cout << Solution().minSwaps(s) << endl;
    s = "1110000000100001010100101010000101010101001000001110101000010111101100000111110001000111010111101100001100001001100101011110100011111100000000100011111011110111111011110111010100111101011111111101101100101010110000011110110100101111000100000001100000";
    cout << Solution().minSwaps(s) << endl;

    return 0;
}
