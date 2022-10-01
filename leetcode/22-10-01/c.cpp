#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdint>
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
#include <unordered_set>
#include <vector>
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
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
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2) {
        int xor1 = 0, xor2 = 0;
        for (auto &&v : nums1) {
            xor1 ^= v;
        }
        for (auto &&v : nums2) {
            xor2 ^= v;
        }
        if (nums1.size() % 2 == 0 && nums2.size() % 2 == 0)
            return 0;
        else if (nums1.size() % 2 == 0)
            return xor1;
        else if (nums2.size() % 2 == 0)
            return xor2;
        else
            return xor1 ^ xor2;
    }
};

int main(int argc, char const *argv[]) { return 0; }
