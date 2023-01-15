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
    bool isItPossible(string word1, string word2) {
        const int maxn = 26;
        vector<int> cnts1(maxn, 0), cnts2(maxn, 0);
        for (auto &&v : word1) {
            cnts1[v - 'a'] += 1;
        }
        for (auto &&v : word2) {
            cnts2[v - 'a'] += 1;
        }
        int total1 = 0, total2 = 0;
        for (auto &&v : cnts1) {
            total1 += (v != 0);
        }
        for (auto &&v : cnts2) {
            total2 += (v != 0);
        }
        for (int i = 0; i < maxn; i++) {
            if (cnts1[i] == 0) continue;
            for (int j = 0; j < maxn; j++) {
                if (cnts2[j] == 0) continue;
                vector<int> nc1 = cnts1, nc2 = cnts2;
                int nt1 = total1, nt2 = total2;
                if (nc1[i] == 1) nt1 -= 1;
                nc1[i] -= 1;
                if (nc1[j] == 0) nt1 += 1;
                if (nc2[j] == 1) nt2 -= 1;
                nc2[j] -= 1;
                if (nc2[i] == 0) nt2 += 1;
                if (nt1 == nt2) return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().isItPossible("aa", "bcd") << endl;
    cout << Solution().isItPossible("aa", "ab") << endl;
    return 0;
}
