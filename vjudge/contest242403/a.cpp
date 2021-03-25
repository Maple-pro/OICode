#include <bits/stdc++.h>
using namespace std;

set<int> digits;
bool has = false;

bool getDigit(int m, int n)
{
	for (int i = 0; i < 5; i++) {
		int digit1 = m % 10;
		m = m / 10;
		int digit2 = n % 10;
		n = n / 10;
		digits.insert(digit1);
		digits.insert(digit2);
	}
	if (m != 0) return false;
	else return true;
} 

int main()
{
	int n;
	int num = 0;
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		if (num > 0) printf("\n");
		num++;
		has = false;
		
		for (int i = 1000; i <= 99999; i++) {
			int j = i * n;
			digits.clear();
			int flag = getDigit(j, i);
			if (!flag) break;
			if (digits.size() != 10) continue;
			has = true;
			printf("%05d / %05d = %d\n", j, i, n);
		}
		if (!has) printf("There are no solutions for %d.\n", n);
	}
	
	return 0;
}
