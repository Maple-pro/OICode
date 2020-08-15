/**
 * @author: Maples
 * @create: 2020/08/09
 * @contest: CF #663
 * @problem: B
 * @description: 
 * @difficulty: 
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
const int maxm = 105;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        char temp;
        int result = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <=m; j++)
            {
                cin >> temp;
                if (i != n && j == m && temp == 'R') result++;
                if (i == n && j != m && temp == 'D') result++;
            }
        }
        cout << result << endl;
    }

    // system("pause");
    return 0;
}