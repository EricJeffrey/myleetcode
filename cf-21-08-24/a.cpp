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
    //
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> nums = {0};
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            nums.push_back(x);
        }
        auto check = [&nums]() {
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1])
                    return false;
            }
            return true;
        };
        int it = 0;
        while (true) {
            if (check()) {
                break;
            }
            it++;
            for (int i = 1; i <= n - 2; i += 2) {
                if (nums[i] > nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                }
            }
            if (check()) {
                break;
            }
            it++;
            for (int i = 2; i <= n - 1; i += 2) {
                if (nums[i] > nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                }
            }
        }
        cout << it << endl;
    }
    return 0;
}
