/**
 * @author: Maples
 * @create: 2020/09/10
 * @contest: 
 * @problem: WOJ184
 * @description: 
 * @difficulty: 
 */


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int result = floor(sqrt(n));
        cout << result << endl;
    }

    // system("pause");
    return 0;
}