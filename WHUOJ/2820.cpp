#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ans = 0;
	for (int b = 23; b < 45; b++) {
		if (45 * b % (2 * b - 45) == 0) ans++;
	}
	cout << ans << endl;
	return 0;
}
