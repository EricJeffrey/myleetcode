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

const int MAXN = 1005;

struct Tree {
    struct node {
        int l, r;
        int add;
        int sum;
        int mx;
    } tree[MAXN << 2];

    void pushup(int index) {
        tree[index].sum = tree[index << 1].sum + tree[index << 1 | 1].sum;
        tree[index].mx = max(tree[index << 1].mx, tree[index << 1 | 1].mx);
    }
    void pushdown(int index) {
        if (tree[index].add) {
            tree[index << 1].sum += (tree[index << 1].r - tree[index << 1].l + 1) * tree[index].add;
            tree[index << 1 | 1].sum += (tree[index << 1 | 1].r - tree[index << 1 | 1].l + 1) * tree[index].add;
            tree[index << 1].mx += tree[index].add;
            tree[index << 1 | 1].mx += tree[index].add;
            tree[index << 1].add += tree[index].add;
            tree[index << 1 | 1].add += tree[index].add;
            tree[index].add = 0;
        }
    }
    void build(int l, int r, int index) {
        tree[index].l = l;
        tree[index].r = r;
        tree[index].add = 0;
        if (l == r) {
            scanf("%d", &tree[index].sum);
            tree[index].mx = tree[index].sum;
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, index << 1);
        build(mid + 1, r, index << 1 | 1);
        pushup(index);
    }
    void updata(int l, int r, int index, int val) {
        if (l <= tree[index].l && r >= tree[index].r) {
            tree[index].sum += (tree[index].r - tree[index].l + 1) * val;
            tree[index].mx += val;
            tree[index].add += val; //延时标记
            return;
        }
        pushdown(index);
        int mid = (tree[index].l + tree[index].r) >> 1;
        if (l <= mid)
            updata(l, r, index << 1, val);
        if (r > mid)
            updata(l, r, index << 1 | 1, val);
        pushup(index);
    }
    int query(int l, int r, int index) {
        if (l <= tree[index].l && r >= tree[index].r)
            return tree[index].mx;

        pushdown(index);
        int mid = (tree[index].l + tree[index].r) >> 1;
        int ans = 0, Max = 0;
        if (l <= mid) {
            ans += query(l, r, index << 1);
            Max = max(query(l, r, index << 1), Max);
        }
        if (r > mid) {
            ans += query(l, r, index << 1 | 1);
            Max = max(query(l, r, index << 1 | 1), Max);
        }
        return Max;
    }
};
bool work(int n, int m, int a, int b, vector<vector<int>> nums) {
    int maxv = 0;
    for (auto &&xs : nums)
        for (auto &&y : xs)
            maxv = max(maxv, y);

    vector<vector<int>> targets(n, vector<int>(m, 0));
    vector<Tree> segtrees(n);
    for (int i = 0; i < n; i++)
        segtrees[i].build(1, n, 1);
    int x = 0, y = 0;
    while (x < n) {
        if (y >= m) {
            x += 1;
            y = 0;
            continue;
        }
        int u = nums[x][y] - segtrees[x].query(y + 1, y + 1, 1);
        if (u != 0)
            for (int i = 0; i < a; i++) {
                int vx = x + i;
                segtrees[vx].updata(y + 1, y + b, 1, u);
                if (segtrees[vx].query(1, m, 1) > maxv)
                    return false;
            }
        y += 1;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, a, b;
        scanf("%d %d %d %d", &n, &m, &a, &b);
        vector<vector<int>> nums(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                scanf("%d", &x);
                nums[i][j] = x;
            }
        }
        auto res = work(n, m, a, b, nums);
        if (res)
            printf("^_^\n");
        else
            printf("QAQ\n");
    }
    return 0;
}
