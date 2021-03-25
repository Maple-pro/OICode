#include <bits/stdc++.h>
using namespace std;

int partition(int *a, int low, int high) {
    int base = a[low];
    while (low < high) {
        while (low < high && a[high] >= base) high--;
        a[low] = a[high];
        while (low < high && a[low] <= base) low++;
        a[high] = a[low];
    }
    a[low] = base;
    return low;
}

// �ҳ�����a��[low, high]��Χ�ĵ�k��
int selectk(int a[], int k, int low, int high) {
    int j = partition(a, low, high);
    if (j == k) {
        return a[j];
    }
    else if (j > k) {
        return selectk(a, k, low, j - 1);
    }
    else {
        return selectk(a, k, j+1, high);
    }
}

int main()
{
	int a[10] = {2, 1, 3, 4, 7, 9, 8, 10, 5, 11};
	// �ҳ���6���ֵ 
    cout << selectk(a, 5, 0, 9);
    
    return 0;
}
