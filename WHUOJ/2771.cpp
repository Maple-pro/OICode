#include <bits/stdc++.h>
using namespace std;

int main()
{
	int r;
	cin >> r;
	double PI = atan(1.0) * 4;
	double res = PI * pow(r, 2);
	printf("%.7f", res);
	return 0;
}
