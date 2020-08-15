/**
 * @author: Maples
 * @create: 2020/09/08
 * @contest: 
 * @problem: POJ 3617
 * @description: 贪心
 * @difficulty: **
 */

#include <iostream>
using namespace std;

const int maxn = 2000 + 5;
char a[maxn];
char result[maxn];

int main()
{
    int N;  
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    int s = 0;
    int t = N - 1;
    int num = 0;
    while (s <= t)
    {
        bool flag = false;
        for (int i = 0; s + i <= t; i++)
        {
            if (a[s + i] < a[t - i])
            {
                flag = true;
                break;
            }
            else if (a[s + i] > a[t - i])
            {
                flag = false;
                break;
            }
        }
        if (flag) 
        {
            result[num] = a[s];
            s++;
        }
        else
        {
            result[num] = a[t];
            t--;
        }
        num ++;
    }
    for (int i = 0; i < num; i++)
    {
        cout << result[i];
        if ((i + 1) % 80 == 0)
        {
            cout << endl;
        }
        
    }
    // system("pause");
    return 0;
}