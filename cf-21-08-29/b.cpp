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

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        vector<int> poslist[2];
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            x %= 2;
            nums.push_back(x);
            poslist[x].push_back(i);
        }

        int64_t res = 0;
        if (poslist[0].size() == poslist[1].size()) {
            int64_t res1 = 0;
            int64_t res2 = 0;
            for (int i = 0; i < n; i++)
                if (i % 2 == 0)
                    res1 += abs(poslist[0][i / 2] - i);
                else
                    res2 += abs(poslist[0][i / 2] - i);
            res = min(res1, res2);
        }
        else {
            if (labs(poslist[0].size() - poslist[1].size()) > 1)
                res = -1;
            else {
                int whomore = poslist[0].size() > poslist[1].size() ? 0 : 1;
                for (int i = 0; i < n; i++) {
                    if (i % 2 == 0)
                        res += abs(poslist[whomore][i / 2] - i);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
