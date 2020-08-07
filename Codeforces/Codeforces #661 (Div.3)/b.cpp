/**
 * @author: Maples
 * @create: 2020/08/05
 * @contest: CF #661
 * @problem: B
 * @description: 
 * @difficulty: 
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 55;
ll a[maxn];
ll b[maxn];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll result = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int minA = *min_element(a, a + n);
        int minB = *min_element(b, b + n);

        for (int i = 0; i < n; i++)
        {
            int x = a[i] - minA;
            int y = b[i] - minB;
            int z = std::min(x, y);
            result += x + y - z;
        }
        cout << result << endl;
    }

    // system("pause");
    return 0;
}
