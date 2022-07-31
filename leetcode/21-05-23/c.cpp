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
    bool canReach(string s, int minJump, int maxJump) {
        const size_t sz = s.size();
        vector<int> prefix(sz + 2, 0);
        auto lowbit = [](int x) { return x & (-x); };
        auto update = [sz, lowbit, &prefix](int i, int val) {
            while (i <= sz + 1) {
                prefix[i] += val;
                i += lowbit(i);
            }
        };
        auto getsum = [lowbit, &prefix](int i) {
            int res = 0;
            while (i > 0) {
                res += prefix[i];
                i -= lowbit(i);
            }
            return res;
        };
        if (s[sz - 1] != '0')
            return false;
        update(sz - minJump + 1, -1);
        update(sz - maxJump, 1);
        for (int i = sz - 2; i >= 0; i--) {
            if (s[i] == '0' && getsum(i + 1) > 0) {
                if (i + 1 - minJump + 1 > 0) {
                    update(i + 1 - minJump + 1, -1);
                    if (i + 1 - maxJump > 0)
                        update(i + 1 - maxJump, 1);
                    else
                        update(1, 1);
                }
            }
        }
        return getsum(1) > 0;
    }
};

int main(int argc, char const *argv[]) {
    string s;
    int minJump;
    int maxJump;
    s = "00";
    minJump = 1;
    maxJump = 1;
    cout << Solution().canReach(s, minJump, maxJump) << endl;
    return 0;
}
