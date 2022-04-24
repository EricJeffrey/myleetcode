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
    bool checkZeroOnes(string s) {
        int lengthof1 = 0, lengthof0 = 0;
        for (int i = 0; i < s.size();) {
            if (s[i] == '1') {
                int tmp = 0;
                while (i < s.size() && s[i] == '1') {
                    tmp++;
                    i++;
                }
                lengthof1 = max(lengthof1, tmp);
            } else {
                int tmp = 0;
                while (i < s.size() && s[i] == '0') {
                    tmp++;
                    i++;
                }
                lengthof0 = max(lengthof0, tmp);
            }
        }
        return lengthof1 > lengthof0;
    }
};

int main(int argc, char const *argv[]) {
    cout << "hello world" << endl;
    return 0;
}
