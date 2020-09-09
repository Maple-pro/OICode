/**
 * @author: Maples
 * @create: 2020/08/06
 * @contest: CF #661
 * @problem: C
 * @description: 暴力，贪心，双指针
 * @difficulty: **
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
int w[maxn];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(w, 0, sizeof(w));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            w[temp]++;
        }
        
    }
}