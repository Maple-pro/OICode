#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

class segmentTree {
private:
    vector<ll> tree, add, mul;
public:
    void init(int n) {
        tree.resize(n << 2);
        add.resize(n << 2);
        mul.resize(n << 2);
    }

    void pushup(int i) {
        tree[i] = (tree[i << 1] + tree[i << 1 | 1]) % mod;
    }

    void pushdown(int i, int l, int r) {
        int mid = l + r >> 1;
        tree[i << 1] = (tree[i << 1] * mul[i] + ll(mid - l + 1) * add[i]) % mod;
        tree[i << 1 | 1] = (tree[i << 1 | 1] * mul[i] + ll(r - mid) * add[i]) % mod;
        mul[i << 1] = (mul[i << 1] * mul[i]) % mod;
        mul[i << 1 | 1] = (mul[i << 1 | 1] * mul[i]) % mod;
        add[i << 1] = (add[i << 1] * mul[i] + add[i]) % mod;
        add[i << 1 | 1] = (add[i << 1 | 1] * mul[i] + add[i]) % mod;
        mul[i] = 1;
        add[i] = 0;
    }

    void build(int i, int l, int r) {
        add[i] = 0;
        mul[i] = 1;
        if (l == r) {
            tree[i] = 0;
            return;
        }
        int mid = l + (r - l) / 2;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
        pushup(i);
    }

    void update1(int i, int l, int r, int m, int n, ll k) {//区间加k
        if (m <= l && r <= n) {
            add[i] = (add[i] + k) % mod;
            tree[i] = (tree[i] + (r - l + 1LL) * k) % mod;
            return;
        }
        pushdown(i, l, r);
        int mid = l + (r - l) / 2;
        if (m <= mid) update1(i << 1, l, mid, m, n, k);
        if (n > mid) update1(i << 1 | 1, mid + 1, r, m, n, k);
        pushup(i);
    }

    void update2(int i, int l, int r, int m, int n, ll k) {//区间乘k
        if (m <= l && r <= n) {
            tree[i] = tree[i] * k % mod;
            mul[i] = mul[i] * k % mod;
            add[i] = add[i] * k % mod;
            return;
        }
        pushdown(i, l, r);
        int mid = l + (r - l) / 2;
        if (m <= mid) update2(i << 1, l, mid, m, n, k);
        if (n > mid) update2(i << 1 | 1, mid + 1, r, m, n, k);
        pushup(i);
    }

    ll query(int i, int l, int r, int m, int n) {
        if (m <= l && r <= n) return tree[i];
        ll ans = 0;
        int mid = l + (r - l) / 2;
        pushdown(i, l, r);
        if (m <= mid) ans = (ans + query(i << 1, l, mid, m, n)) % mod;
        if (n > mid) ans = (ans + query(i << 1 | 1, mid + 1, r, m, n)) % mod;
        return ans;
    }
};

int n, m, op, l, r;
ll k;

int main() {
    scanf("%d%d", &n, &m);
    if (n <= 1000 && m <= 1000) {
        ll x[1005] = {0}, y[1005] = {0}, z[1005] = {0};
        while (m--) {
            scanf("%d%d%d", &op, &l, &r);
            if (op == 1) {
                ll a, b, c;
                scanf("%lld%lld%lld", &a, &b, &c);
                for (int i = l; i <= r; i++) {
                    x[i] = (x[i] + a) % mod, y[i] = (y[i] + b) % mod, z[i] = (z[i] + c) % mod;
                }
            } else if (op == 2) {
                scanf("%lld", &k);
                for (int i = l; i <= r; i++) {
                    x[i] = (x[i] * k) % mod, y[i] = (y[i] * k) % mod, z[i] = (z[i] * k) % mod;
                }
            } else if (op == 3) {
                for (int i = l; i <= r; i++) {
                    swap(x[i], y[i]);
                    swap(y[i], z[i]);
                }
            } else {
                ll X = 0, Y = 0, Z = 0;
                for (int i = l; i <= r; i++) {
                    X = (X + x[i]) % mod, Y = (Y + y[i]) % mod, Z = (Z + z[i]) % mod;
                }
                printf("%lld\n", (X * X % mod + Y * Y % mod + Z * Z % mod) % mod);
            }
        }
    } else {
        segmentTree x = segmentTree();
        segmentTree y = segmentTree();
        segmentTree z = segmentTree();
        x.init(n);
        y.init(n);
        z.init(n);
        x.build(1, 1, n);
        y.build(1, 1, n);
        z.build(1, 1, n);
        while (m--) {
            scanf("%d%d%d", &op, &l, &r);
            if (op == 1) {
                ll a, b, c;
                scanf("%lld%lld%lld", &a, &b, &c);
                x.update1(1, 1, n, l, r, a);
                y.update1(1, 1, n, l, r, b);
                z.update1(1, 1, n, l, r, c);
            } else if (op == 2) {
                ll k;
                scanf("%lld", &k);
                x.update2(1, 1, n, l, r, k);
                y.update2(1, 1, n, l, r, k);
                z.update2(1, 1, n, l, r, k);
            } else if (op == 3) {
                continue;
            } else {
                ll X = 0, Y = 0, Z = 0;
                X = x.query(1, 1, n, l, r);
                Y = y.query(1, 1, n, l, r);
                Z = z.query(1, 1, n, l, r);
                printf("%lld\n", (X * X % mod + Y * Y % mod + Z * Z % mod) % mod);
            }
        }
    }
    return 0;
}
