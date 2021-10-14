#include <bits/stdc++.h>
using namespace std;

int a[13] = {7, 2, 6, 5, 4, 11, 8, 5, 3, 5, 1, 9, 5};

int partition(int start, int end)
{
	auto base = a[start];
	int left = start;
	int right = end;
	while (left < right)
	{
		while (right > left && a[right] >= base) right--;
		a[left] = a[right];
		while (left < right && a[left] < base) left++;
		a[right] = a[left];
	}
	a[left] = base;
	return left;
}

void quicksort(int l, int r)
{
	if (l < r) {
		int index = partition(l, r);
		quicksort(l, index - 1);
		quicksort(index + 1, r);
	}
}

int main()
{
	quicksort(0, 12);
	
	for (int i = 0; i < 13; i++) printf("%d\n", a[i]);
	
	system("pause");
	return 0;
}
