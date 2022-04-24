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
    int numneg, numpos, num0;
    numneg = numpos = num0 = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x < 0) numneg++;
      if (x == 0) num0++;
      if (x > 0) numpos++;
    }
    bool res = false;
    if (abs(numneg - numpos) - num0 <= 1) res = true;
    cout << (res ? "Yes" : "No") << endl;
  }
  return 0;
}
