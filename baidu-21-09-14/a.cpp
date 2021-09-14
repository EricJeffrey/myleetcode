#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    vector<int> values(k, 0);
    for (int i = 0; i < k; i++) {
        values[i] = n * (i + 1);
    }
    int v = 0;
    for (int i = 0; i < k; i++) {
        string s = to_string(values[i]);
        std::reverse(s.begin(), s.end());
        values[i] = std::stoi(s);
        v = max(v, values[i]);
    }
    cout << v << endl;

    return 0;
}
