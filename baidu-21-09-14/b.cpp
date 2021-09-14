#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    string a;
    cin >> a;
    const int n = a.size();
    if (a[0] == a[n - 1]) {
        cout << 1 << " " << n - 1 << ' ' << 2 << ' ' << n << endl;
    } else {
        int i = 0, j = n - 1;
        while (i < n - 1 && a[i] != a[n - 1])
            i++;
        while (j > 0 && a[j] != a[0])
            j--;
        vector<int> res;
        if (n - 1 - i > j)
            res = {i + 1, n - 1, i + 2, n};
        else
            res = {1, j, 2, j + 1};
        for (int k = 0; k < 4; k++) {
            if (k != 0)
                cout << ' ';
            cout << res[k];
        }
        cout << endl;
    }
    return 0;
}
