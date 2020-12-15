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
    string removeDuplicates(string s, int k) {
        typedef pair<char, int> PCI;
        stack<PCI> sta;
        for (size_t i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (sta.empty() || sta.top().first != ch)
                sta.push({ch, 1});
            else {
                PCI tmppair = sta.top();
                sta.pop();
                if (tmppair.second < k - 1)
                    sta.push({ch, tmppair.second + 1});
            }
        }
        string res;
        while (!sta.empty()) {
            auto tmppair = sta.top();
            sta.pop();
            res = string(tmppair.second, tmppair.first) + res;
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    auto testout = [](string s, int k) {
        cout << Solution().removeDuplicates(s, k) << endl;
    };
    testout("abcd", 5);
    testout("deeedbbcccbdaa", 3);
    testout("pbbcggttciiippooaais", 2);
    return 0;
}
