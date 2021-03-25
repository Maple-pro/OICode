// Undone

#include <bits/stdc++.h>
using namespace std;

int getRes(int a, int b, int num)
{
	if (a < b) {
		num++;
		return num;
	}
	else if (b == 1) {
		num++;
		b++;
		return getRes(a, b, num);
	}
	else {
		a = a / b;
		num++;
		return getRes(a, b, num);
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		cout << getRes(a, b, 0) << endl;
	}
	return 0;
} 
