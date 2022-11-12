
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
    vector<string> splitMessage(string message, int limit) {
        int t;
        for (t = 1; t <= limit; t++) {
            int a = limit - t - 3;
            int cnt = 0;
            for (int i = 1; i <= t && i <= a; i++) {
                cnt += (a - i) * 9 * pow(10, i - 1);
            }
            if (cnt >= message.size()) break;
        }
        cout << "DEBUG, t: " << t << endl;
        if (t > limit) return {};
        int a = limit - t - 3;
        int start = 0;
        int index = 1;
        vector<string> res;
        for (int i = 1; a - i > 0; i++) {
            int len = a - i;
            int cnt = min(9 * pow(10, i - 1), 1e4);
            while (cnt-- && start < message.size()) {
                res.push_back(message.substr(start, len) + "<" + to_string(index) + "/");
                start += len;
                index += 1;
            }
        }
        for (size_t i = 0; i < res.size(); i++) {
            res[i] += to_string(index - 1) + ">";
        }
        return res;
    }
};

int main() {
    string message;
    int limit;
    message = "this is really a very awesome message", limit = 9;
    vector<string> res;
    res = Solution().splitMessage(message, limit);
    for (auto &&v : res) {
        cout << v << " ";
    }
    cout << endl;
    message = "short message", limit = 15;
    res = Solution().splitMessage(message, limit);
    for (auto &&v : res) {
        cout << v << " ";
    }
    cout << endl;
    message = "s", limit = 15;
    res = Solution().splitMessage(message, limit);
    for (auto &&v : res) {
        cout << v << " ";
    }
    cout << endl;
    message = "ssdffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", limit = 7;
    res = Solution().splitMessage(message, limit);
    for (auto &&v : res) {
        cout << v << " ";
    }
    cout << endl;
}
