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
    int minimizeXor(int num1, int num2) {
        string s1 = bitset<32>((unsigned int)num1).to_string();
        string s2 = bitset<32>((unsigned int)num2).to_string();
        int cnt1ofs2 = 0;
        for (auto &&ch : s2) {
            if (ch == '1') cnt1ofs2 += 1;
        }
        string res(32, '0');
        int j = 0;
        for (size_t i = 0; i < res.size() && j < cnt1ofs2; i++) {
            if (s1[i] == '1') {
                res[i] = '1';
                j += 1;
            }
        }
        if (j < cnt1ofs2) {
            for (int i = res.size() - 1; i >= 0 && j < cnt1ofs2; i--) {
                if (res[i] == '0') {
                    res[i] = '1';
                    j += 1;
                }
            }
        }
        return stoi(res, 0, 2);
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().minimizeXor(3, 5) << endl;
    cout << Solution().minimizeXor(1, 12) << endl;
    return 0;
}
