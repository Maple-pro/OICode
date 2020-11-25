#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int a;
	int b;
} score;

const int maxn = 25 * 2500;
char ch[maxn];

int main()
{
	score s1; s1.a = 0; s1.b = 0;
	score s2; s2.a = 0; s2.b = 0;
	
	int cnt = 0;
	while (true) {
		char x;
		cin >> x;
		if (x == 'E') break;
		ch[cnt] = x;
		cnt++;
	}
	
	for (int i = 0; i < cnt; i++) {
		if (ch[i] == 'W') {
			s1.a++;
		}
		if (ch[i] == 'L') {
			s1.b++;
		}
		if ((s1.a >= 11 || s1.b >= 11) && abs(s1.a - s1.b) >= 2) {
			cout << s1.a << ':' << s1.b << endl;
			s1.a = 0; s1.b = 0;
		}
	}
	cout << s1.a << ':' << s1.b << endl;
	cout << endl;
	
	for (int i = 0; i < cnt; i++) {
		if (ch[i] == 'W') {
			s2.a++;
		}
		if (ch[i] == 'L') {
			s2.b++;
		}
		if ((s2.a >= 21 || s2.b >= 21) && abs(s2.a - s2.b) >= 2) {
			cout << s2.a << ':' << s2.b << endl;
			s2.a = 0; s2.b = 0;
		}
	}
	cout << s2.a << ':' << s2.b << endl;
	return 0;
}
