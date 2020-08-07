/**
 * @author: Maples
 * @create: 2020/08/05
 * @contest: CF #661
 * @problem: A
 * @description: 
 * @difficulty: 
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
int a[maxn];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (n == 1)
        {
            cout << "YES" << endl;
            continue;
        }

        sort(a, a + n);
        bool flag = true;
        for (int i = 0; i < n-1; i++)
        {
            if ((a[i + 1] - a[i]) > 1)
            {
                flag = false;
                break;
            }
        }

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    // system("pause");
    return 0;
}