#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int index;
	int time;
} p;

const int maxn = 1005;
p t[maxn];

bool comp(p p1, p p2) {
	return p1.time < p2.time;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		t[i].index = i + 1;
		cin >> t[i].time;
	}
	sort(t, t + n, comp);
	
//	for (int i = 0; i < n; i++) cout << t[i].index << " " << t[i].time << endl;
	
	long long ans = 0;
	long long pre = 0;
	for (int i = 0; i < n - 1; i++) {
		ans += pre + t[i].time;
		pre += t[i].time;
	}
	double aver = ans/(double)n;
	for (int i = 0; i < n; i++) {
		cout << t[i].index << " ";
	}
	cout << endl;
	printf("%.2f\n", aver);
	
	return 0;
}
