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

int gcd(int a, int b) {
    if (a < b)
        swap(a, b);
    if (a % b == 0)
        return b;
    return gcd(a % b, b);
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int res = 1;
        for (int i = 2; i * i < n; i++) {
            if (n % i == 0 && gcd(i, n / i) == 1)
                res++;
        }
        cout << res << endl;
    }

    return 0;
}
