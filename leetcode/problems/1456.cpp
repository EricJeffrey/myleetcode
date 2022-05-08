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
    int maxVowels(string s, int k) {
        vector<int> nums(s.size(), 0);
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                nums[i] = 1;
        }
        for (size_t i = 1; i < s.size(); i++) {
            nums[i] = nums[i - 1] + nums[i];
        }
        int res = nums[k - 1];
        for (size_t i = 1; i <= s.size() - k; i++) {
            res = max(res, nums[i + k - 1] - nums[i - 1]);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    auto testout = [](string s, int k) {
        cout << Solution().maxVowels(s, k) << endl;
    };
    testout("abciiidef", 3);
    testout("aeiou", 2);
    testout("leetcode", 3);
    testout("rhythms", 4);
    testout("tryhard", 4);
    testout("weallloveyou", 7);
    return 0;
}
