#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 3e3 + 1;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp(n, 0);
    int lastv = 0;
    int curcnt[26] = {};
    for (int i = 0; i < n; i++) {
        int which = s[i] - 'a';
        if (curcnt[which] == 0) lastv -= 1;
        else if (curcnt[which] % 2 == 0)
            lastv -= 2;
        else
            lastv += 2;
        curcnt[which] += 1;
        dp[i] = lastv;
    }
    for (int i = 1; i < n; i++) {
        int tmpcnt[26] = {};
        int x = 0;
        for (int k = 1; k <= i; k++) {
            int which = s[i - k + 1] - 'a';
            if (tmpcnt[which] == 0) x -= 1;
            else if (tmpcnt[which] % 2 == 0)
                x -= 2;
            else
                x += 2;
            tmpcnt[which] += 1;
	    dp[i] = max(dp[i], dp[i - k] + x);
	    
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}
