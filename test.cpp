#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int C[8];

void search(int cnt)
{
	if (cnt == 8) ans++;
	else {
		for (int i = 0; i < 8; i++) {
			C[cnt] = i;
			bool flag = true;
			for (int j = 0; j < cnt; j++) {
				if(C[cnt] == C[j] || abs(C[cnt] - C[j]) == abs(cnt - j))  {
					flag = false;
					break;
				}   
			}
			if (!flag) continue;
			else {
				search(cnt+1); 
			}
		}
	}
} 

int main()
{
	search(0);
	printf("%d\n", ans);
	return 0;
}
