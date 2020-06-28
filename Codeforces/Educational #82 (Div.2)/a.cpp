#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
char s[maxn];

int main()
{
	int t;
	cin >>t;
	while (t--)
	{
		scanf("%s", s);
		bool flag = false; //start count?
		int temp = 0;
		int result = 0;
		int length = strlen(s);
		for (int i=0; i<length; i++)
		{
			if (s[i] == '0')
			{
				if (flag) 
					temp++;
			}
			if (s[i] == '1')
			{
				if (flag)
				{
					result += temp;
					temp = 0;
				}
				else
				{
					flag = true;
				}
			}
		}
		cout << result << endl;
	}

	return 0;
}