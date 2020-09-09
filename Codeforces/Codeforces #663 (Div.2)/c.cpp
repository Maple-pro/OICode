/**
 * @author: Maples
 * @create: 2020/08/10
 * @contest: CF #663
 * @problem: C
 * @description: 
 * @difficulty: 
 */

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const ll mod = 1e9 +7;
const int maxn = 1e6 + 5;
ll a[maxn];

int main()
{
    int n;
    cin >> n;
    a[3] = 2;
    for (int i = 4; i <= 1e6; i++)
    {
        a[i] = (((i-2) * (i-1) * a[i-1]) / (n-3)) % mod;
    }
    ll result = 0;
    for (int i = 3; i <= n-1; i++)
    {
        result = (result + 2 * a[i]) % mod;
    }
    result = (result + a[n]) % mod;

    cout << result << endl;

    system("pause");
    return 0;
}