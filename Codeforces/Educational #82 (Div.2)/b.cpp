#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int T; cin >> T;
	while (T--)
	{
		ll n, g, b;
		ll result;
		cin >> n >> g >> b;

		if (g >= b) result = n;
		else{
			ll result1 = (g + b) * (n / (2*g));
			if (n % (2*g) == 0)
			{
				result = result1 - b;
			}
			else{
				ll yu = n % (2*g);
				ll chu = n / (2*g);
				ll result2;
				if (chu*(b-g) >= (yu/2)){
					result2 = yu - yu/2;
				}
				else{
					result2 = yu - chu * (b-g);
				}
				result = result + result2;
			}
		}
		cout << result << endl;
	}
	return 0;
}