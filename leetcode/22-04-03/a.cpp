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
    int convertTime(string current, string correct) {
        int curh = stoi(current.substr(0, 2)), curm = stoi(current.substr(3));
        int corh = stoi(correct.substr(0, 2)), corm = stoi(correct.substr(3));
        int curam = curh * 60 + curm;
        int coram = corh * 60 + corm;
        int dif = coram - curam;
        int res = dif / 60;
        dif = dif % 60;
        res += dif / 15;
        dif = dif % 15;
        res += dif / 5;
        dif = dif % 5;
        res += dif;
        return res;
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().convertTime("02:30", "04:35") << endl;
    cout << Solution().convertTime("11:00", "11:01") << endl;
    return 0;
}
