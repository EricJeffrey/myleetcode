#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    multiset<int> s;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        s.insert(nums[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0)
            s.erase(s.find(nums[i - 1]));
        multiset<int> tmps = s;
        for (int j = n - 1; j > i; j--) {
            if (j < n - 1)
                tmps.erase(tmps.find(nums[j + 1]));
            int u = nums[i], v = nums[j];
            auto tmpit = tmps.begin();
            int s1 = *tmpit;
            tmpit++;
            int s2 = *tmpit;
            if ((u == s1 && v == s2) || (u == s2 && v == s1))
                res++;
        }
    }
    cout << res << endl;
    return 0;
}
