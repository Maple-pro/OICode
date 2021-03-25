#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int s = a + b;
    if (s < 0) printf("-");
    s = abs(s);
    int res[10];
    int i;
    if (s == 0) {
    	printf("%d", 0);
    	return 0;
	}
    for (i = 0; ; i++) {
        if (s == 0) break;
        res[i] = s % 10;
        s = s / 10;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", res[j]);
        if (j % 3 == 0 && j != 0) printf(",");
    }
    
    return 0;
}
