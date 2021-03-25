#include <bits/stdc++.h>
using namespace std;

int main()
{
	int year, month, day;
	cin >> year >> month >> day;
	if (month <= 2) {
		month += 12;
		year--;
	}
	int x;
	int c = int(year / 100);
	int y = year - 100 * c;
	int w = int(c / 4) - 2 * c + y + int(y / 4) + (26 * (month + 1) / 10) + day - 1;
	w = (w % 7 + 7) % 7;
	if (w == 0) w = 7;
	cout << w << endl;
	return 0;
}
