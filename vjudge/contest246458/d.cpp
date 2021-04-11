#include <bits/stdc++.h>
using namespace std;

bool solve(int &w)
{
	int wl, dl, wr, dr;
	scanf("%d%d%d%d", &wl, &dl, &wr, &dr);
	bool b1 = true;
	bool b2 = true;
	if (!wl) b1 = solve(wl);
	if (!wr) b2 = solve(wr);
	w = wl + wr;
	return b1 && b2 && (wl * dl == wr * dr);
}

int main()
{
//	freopen("./data/d/1.in", "r", stdin);
	
	int t; scanf("%d", &t);
	int w;
	while (t--) {
		bool res = solve(w);
		if (res) printf("YES\n");
		else printf("NO\n");
		if (t) printf("\n");
	}
	
	return 0;
}
