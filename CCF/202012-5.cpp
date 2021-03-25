// 线段树（加法+乘法）
// 40分（本应该过60分） 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn = 1e7 + 5;
const ll mod = 1e9 + 7;

class segmentTree {
	private:
		vector<ll> data, add, mul, rot;
	public:
		void init(int n)
		{
			data.resize(n << 2);
			add.resize(n << 2);
			mul.resize(n << 2);
			rot.resize(n << 2);
		}
		void pushup(int o)
		{
			data[o] = (data[o << 1] + data[o << 1 | 1]) % mod;
		}
		
		void pushdown(int o, int l, int r)
		{
			int mid = (l + r) >> 1;
			data[o << 1] = (data[o << 1] * mul[o] + ll(mid - l + 1) * add[o]) % mod;
			data[o << 1 | 1] = (data[o << 1 | 1] * mul[o] + ll(r - mid) * add[o]) % mod;
			mul[o << 1] = (mul[o << 1] * mul[o]) % mod;
			mul[o << 1 | 1] = (mul[o << 1 | 1] * mul[o]) % mod;
			add[o << 1] = (add[o << 1] * mul[o] + add[o]) % mod;
			add[o << 1 | 1] = (add[o << 1 | 1] * mul[o] + add[o]) % mod;
			mul[o] = 1;
			add[o] = 0;
		}
		
		void build(int o, int l, int r)
		{
			add[o] = 0;
			mul[o] = 1;
			rot[o] = 0;
			if (l == r) {
				data[o] = 0;
				return;
			}
			int mid = (l + r) >> 1;
			build(o << 1, l, mid);
			build(o << 1 | 1, mid + 1, r);
			pushup(o);
		}
		
		// 对区间[m, n]同时加k
		void add_update(int o, int l, int r, int m, int n, ll k)
		{
			if (m <= l && r <= n) {
				add[o] = (add[o] + k) % mod;
				data[o] = (data[o] + k * ll(r - l + 1)) % mod;
				return;
			}
			pushdown(o, l, r);
			int mid = (l + r) >> 1;
			if (m <= mid) add_update(o << 1, l , mid, m, n, k);
			if (mid < n) add_update(o << 1 | 1, mid + 1, r, m , n, k);
			pushup(o);
		}
		
		// 对区间[m, n]同时乘以k
		void mul_update(int o, int l, int r, int m, int n, ll k)
		{
			if (m <= l && r <= n) {
				mul[o] = (mul[o] * k) % mod;
				data[o] = (data[o] * k) % mod;
				add[o] = (add[o] * k) % mod;
				return; 
			}
			pushdown(o, l, r);
			int mid = (l + r) >> 1;
			if (m <= mid) mul_update(o << 1, l, mid, m, n, k);
			if (n > mid) mul_update(o << 1 | 1, mid + 1, r, m, n, k);
			pushup(o);
		}
		
		// 对区间[m, n]旋转 
		void rot_update(int o, int l, int r, int m, int n)
		{
			
		}
		
		// 对区间[m, n]查询
		ll query(int o, int l, int r, int m, int n)
		{
			if (m <= l && r <= n) return data[o];
			ll ans = 0;
			int mid = (l + r) >> 1;
			pushdown(o, l, r);
			if (m <= mid) ans = (ans + query(o << 1, l, mid, m, n)) % mod;
			if (mid < n) ans = (ans + query(o << 1 | 1, mid + 1, r, m, n)) % mod;
			return ans;
		}
};


int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	segmentTree x = segmentTree();
	segmentTree y = segmentTree();
	segmentTree z = segmentTree();
	x.init(n);
	y.init(n);
	z.init(n);
	x.build(1, 1, n);
	y.build(1, 1, n);
	z.build(1, 1, n);
	for (int i = 0; i < m; i++) {
		ll num, l, r, a, b, c, k;
		scanf("%lld%lld%lld", &num, &l, &r);
		if (num == 1) {
			scanf("%lld%lld%lld", &a, &b, &c);
			x.add_update(1, 1, n, l, r, a);
			y.add_update(1, 1, n, l, r, b);
			z.add_update(1, 1, n, l, r, c);
		}
		else if (num == 2) {
			scanf("%lld", &k);
			x.mul_update(1, 1, n, l, r, k);
			y.mul_update(1, 1, n, l, r, k);
			z.mul_update(1, 1, n, l, r, k);
		}
		else if (num == 3) {
//			x.rot_update(1, 1, n, l, r);
			continue;
		}
		else if (num == 4) {
			ll sumx = 0, sumy = 0, sumz = 0;
			sumx = x.query(1, 1, n, l, r);
			sumy = y.query(1, 1, n, l, r);
			sumz = z.query(1, 1, n, l, r);
			printf("%lld\n", (sumx * sumx % mod + sumy * sumy % mod + sumz * sumz % mod) % mod);
		}
	}
	
	return 0;
}
