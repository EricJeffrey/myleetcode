#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    string s;
    cin >> n >> s;
    s.push_back('x');
    int rc = 0, bc = 0;
    char la = s[0];
    for (int i = 1; i <= n; i++) {
        char ch = s[i];
        if (ch != la) {
            if (la == 'R') rc++;
            else if (la == 'B') bc++;
            else break;
            la = ch;
        }
    }
    int res = rc + bc;
    res = min(res, 1 + min(bc, rc));
    cout << res << endl;
    return 0;
}
