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
    string getPermutation(int n, int k) {
        vector<int> nums;
        int factorial = 1;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
            factorial *= i;
        }
        k -= 1;
        string res;
        for (int i = 1; i < n; i++) {
            factorial /= (n - i + 1);
            int who = k / factorial;
            k %= factorial;
            res += '0' + nums[who];
            nums.erase(nums.begin() + who);
        }
        res += '0' + nums.front();
        return res;
    }
};

int main(int argc, char const *argv[]) {
    auto testout = [](int n, int k) {
        cout << Solution().getPermutation(n, k) << endl;
    };
    testout(5, 33);
    testout(3, 3);
    testout(4, 9);
    testout(3, 1);
    testout(5, 120);
    return 0;
}
