#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
  public:
    int numSquares(int n) {
        if (n <= 3)
            return n;
        int sq = sqrt(n);
        if (sq * sq == n)
            return 1;
        // return goDP(n);
        return bfs(n);
    }
    int bfs(int n) {
        typedef pair<int, int> PII;
        queue<PII> q;
        q.push(PII(0, 0));
        while (!q.empty()) {
            PII tmpPiar = q.front();
            q.pop();
            int fir = tmpPiar.first, sec = tmpPiar.second;
            if (fir == n)
                return sec;
            if (sec == 4)
                continue;
            for (int i = sqrt(n - fir); i >= sqrt((n - fir) / (4 - sec)); i--) {
                int i2 = i * i;
                int tmpfir = fir + i2, tmpsec = sec + 1;
                if (tmpfir == n)
                    return tmpsec;
                q.push(PII(tmpfir, tmpsec));
            }
        }
        return 4;
    }
};
int main(int argc, char const *argv[]) {
    int n;
    while (cin >> n)
        cout << Solution().numSquares(n) << endl;
    return 0;
}
/*
2 3 4 5 6 8 17 18 20 26 27 29 32 37 38 40 41 50 50 51 52 53 61 65 65 66 68 72 74
80 82 83 85 85 89 97 98 100 101 102 104 106 113 116 117 125 128 130 136 145 149
162 164 181 200
*/