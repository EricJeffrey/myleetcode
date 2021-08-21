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

// abzcayzdabzxayz

char getSnK(int n, int k) {
    static vector<char> L = {'0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                             'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    if (n == 1)
        return 'a';
    int sz = (1 << n) - 1;
    if (k == sz / 2) {
        return L[n];
    } else {
        if (k < sz / 2) {
            return getSnK(n - 1, k);
        } else {
            char tmp = getSnK(n - 1, sz - k - 1);
            return L[26 - (tmp - 'a')];
        }
    }
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回Sn的第k位字符
     * @param n int整型 Sn的n
     * @param k int整型 需要返回的字符下标位
     * @return char字符型
     */
    char findKthBit(int n, int k) {
        // write code here
        return getSnK(n, k - 1);
    }
};

int main(int argc, char const *argv[]) {
    int n, k;
    scanf("%d,%d", &n, &k);
    printf("%c\n", Solution().findKthBit(n, k));
    return 0;
}
