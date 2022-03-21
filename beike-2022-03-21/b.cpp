#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;
const int maxn = 1e6 + 1;
int sums[maxn] = {};
int isoknum[maxn] = {};
int pref[maxn] = {};
int main() {
    for (int i = 1; i < 10; i++) sums[i] = i;
    for (int i = 10; i < maxn; i++) {
        sums[i] = sums[i % 10] + sums[i / 10];
    }
    for (int i = 1; i < maxn; i++) {
	if (sums[i] == 0) cout << i << endl;
        isoknum[i] = (i % sums[i] == 1 ? 1: 0);
    }
    for (int i = 1; i < maxn; i++) {
        pref[i] = pref[i - 1] + isoknum[i];
    }
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << endl;
    }
    return 0;
}

