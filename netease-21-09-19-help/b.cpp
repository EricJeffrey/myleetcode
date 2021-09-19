#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int a, b;
    cin >> a >> b;
    if (b % a != 0) {
        cout << -1 << endl;
    } else {
        int v = b / a, cnt = 1;
        while (true) {
            int what = -1;
            for (int i = 2; i * i <= v; i++) {
                if (v % i == 0) {
                    what = i;
                    break;
                }
            }
            if (what != -1) {
                cnt += 1;
                v = v / what;
            } else
                break;
        }
        cout << cnt << endl;
    }
    return 0;
}
