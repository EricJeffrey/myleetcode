#include <algorithm>
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

const int maxn = 65536;
int tree[maxn]; // 线段树
int lz[maxn];   // 延迟标记

void init() {
    memset(tree, 0, sizeof(tree));
    memset(lz, 0, sizeof(lz));
}

// 创建线段树
void build(int node, int l, int r) {
    if (l == r) {
        cin >> tree[node];
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// 单点更新，n为更新值，index为更新点，lr为更新范围
void update(int n, int index, int l, int r, int node) {
    if (l == r) {
        tree[node] = n; // 更新方式，可以自由改动
        return;
    }
    int mid = (l + r) / 2;
    // push_down(node,mid-l+1,r-mid); 若既有点更新又有区间更新，需要这句话
    if (index <= mid) {
        update(n, index, l, mid, node * 2);
    } else {
        update(n, index, mid + 1, r, node * 2 + 1);
    }
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void push_down(int node, int l, int r) {
    if (lz[node]) {
        int mid = (l + r) / 2;
        lz[node * 2] += lz[node];
        lz[node * 2 + 1] += lz[node];
        tree[node * 2] += 1LL * (mid - l + 1) * lz[node];
        tree[node * 2 + 1] += 1LL * (r - mid) * lz[node];
        lz[node] = 0;
    }
}

// 区间更新，lr为更新范围，LR为线段树范围，add为更新值
void update_range(int node, int l, int r, int L, int R, int add) {
    if (l <= L && r >= R) {
        lz[node] += 1LL * add;
        tree[node] += 1LL * (R - L + 1) * add; // 更新方式
        return;
    }
    push_down(node, L, R);
    int mid = (L + R) / 2;
    if (mid >= l) update_range(node * 2, l, r, L, mid, add);
    if (mid < r) update_range(node * 2 + 1, l, r, mid + 1, R, add);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// 区间查找
long long query_range(int node, int l, int r, int L, int R) {
    if (l <= L && r >= R) return tree[node];
    push_down(node, L, R);
    int mid = (L + R) / 2;
    long long sum = 0;
    if (mid >= l) sum += query_range(node * 2, l, r, L, mid);
    if (mid < r) sum += query_range(node * 2 + 1, l, r, mid + 1, R);
    return sum;
}

class Solution {
public:
    int trans(int x) { return x + 1e4 + 1; }

    vector<int> countSmaller(vector<int> &nums) {
        int maxval = 0;
        for (auto &&x : nums)
            maxval = max(trans(x), maxval);
        init();
        vector<int> res;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int x = trans(nums[i]);
            update_range(1, x + 1, maxval, 1, maxval, 1);
            res.push_back(query_range(1, x, x, 1, maxval));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


int main(int argc, char const *argv[]) {
    vector<int> nums;
    nums = {2, 4, 3, 8, 6, 7, 4, 5, 3, 8, 7};
    // nums = {5, 2, 6, 1};
    // nums = {5, 4, 3, 8, 6};
    auto res = Solution().countSmaller(nums);
    for (auto &&x : res)
        cout << x << ", ";
    cout << endl;

    return 0;
}
