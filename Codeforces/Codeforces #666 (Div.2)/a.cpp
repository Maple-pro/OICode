/**
 * @author: Maples
 * @create: 2020/08/30
 * @contest: CF #666
 * @problem: A
 * @description: 
 * @difficulty: 
 */

#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int flag[26];
        memset(flag, 0, sizeof(flag));
        bool result = true;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (char ch: s)
            {
                flag[ch - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (flag[i] % n != 0)
            {
                result = false;
                break;
            }
        }
        if (result) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    // system("pause");
    return 0;

}