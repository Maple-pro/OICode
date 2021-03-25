#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int nums[maxn];

int main()
{
	int n;
	cin >> n;
	getchar();
	int flag = 0;
	string tmp;
	for (int i = 0; i < n; i++) {
		getline(cin, tmp);
		int num = 0;
		for (int j = 0; ; j++) {
			if (tmp[j] == '\0') {
				nums[flag] = num;
				num = 0;
				flag++;
				break;
			}
			if (tmp[j] != ' ') num = num * 10 + tmp[j] - '0';
			else {
				nums[flag] = num;
				num = 0;
				flag++;
			}
		}
		
	}
	
	sort(nums, nums+flag);
//	for (int i = 0; i < flag; i++) cout << nums[i] << endl;
	
	int repeat, lack;
	for (int i = 1; i < flag; i++) {
		if (nums[i-1] == nums[i] && nums[i] != 0) {
			repeat = nums[i];
			break;
		}
	}
	for (int i = 0; i < flag; i++) {
		if (nums[i] != nums[i-1] + 1 && nums[i] != repeat && nums[i-1] != 0) {
			lack = nums[i-1] + 1;
		}
	}
	cout << lack << " " << repeat << endl;
	return 0;
} 
