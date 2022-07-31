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
    string largestGoodInteger(string num) {
        string res;
        for (int i = 0; i + 2 < num.size(); i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                string tmp = num.substr(i, 3);
                if (res.empty() || res < tmp)
                    res = tmp;
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[]) {
    cout << Solution().largestGoodInteger("6777133339") << endl;
    cout << Solution().largestGoodInteger("2300019") << endl;
    cout << Solution().largestGoodInteger("42352338") << endl;
    return 0;
}
