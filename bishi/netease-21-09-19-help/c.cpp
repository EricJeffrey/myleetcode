#include <iostream>
#include <string>
using namespace std;

int calc(string s) {
    string target = "AcMer";
    int res = 0;
    for (int i = 0; i < 5; i++)
        if (s[i] != target[i]) {
            if (tolower(s[i]) == tolower(target[i])) {
                res += 5;
            } else {
                if (islower(s[i]) == islower(target[i])) {
                    res += 5;
                } else {
                    res += 10;
                }
            }
        }
    return res;
}
int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    int cost = 5 * 10;
    for (size_t i = 0; i < s.size() - 4; i++) {
        cost = min(cost, calc(s.substr(i, 5)));
    }
    cout << cost << endl;
    return 0;
}
