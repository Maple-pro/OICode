// uva-679
// Ê÷ 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int l; scanf("%d", &l);
	for (int i = 1; i <= l; i++) {
		int D, I;
		scanf("%d%d", &D, &I);
		int k = 1;
		for (int i = 1; i <= D-1; i++) {
			if (I % 2 == 1) {
				I = (I + 1) / 2;
				k = k << 1;
			}
			else {
				I = I / 2;
				k = k << 1 | 1;
			}
		}
		printf("%d\n", k);
	}
	int end; scanf("%d", &end);
	
	return 0;
}
