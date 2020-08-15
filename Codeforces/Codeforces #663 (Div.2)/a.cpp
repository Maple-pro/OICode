/**
 * @author: Maples
 * @create: 2020/08/09
 * @contest: CF #663
 * @problem: A
 * @description: 
 * @difficulty: 
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            cout << i << " ";
        }
        cout << n << endl;
    }
    // system("pause");
    return 0;
}