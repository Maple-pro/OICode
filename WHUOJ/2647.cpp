#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ans = 0;
	for (double a = 0; a <= 20; a++) {
		for (double b = 0; b <= 40; b++) {
			for (double c = 0; c <= 200; c++) {
				for (int d = 0; d <= 400; d++) {
					if (a * 1.0 + 0.5 * b + 0.1 * c + 0.05 * d == 20.0 && a+b+c+d == 50) {
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
