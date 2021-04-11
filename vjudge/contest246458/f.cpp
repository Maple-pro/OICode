#include <bits/stdc++.h>
using namespace std;

const int len = 32;
const int maxn = 1024 + 5;
int image[len][len];
int cnt;

// w±ß³¤, (row, col)×óÉÏ½Ç×ø±ê, index×Ö·û 
void draw(string s, int w, int row, int col, int& index)
{
	char ch = s[index];
	index++;
	if (ch == 'p') {
		draw(s, w / 2, row, col + w / 2, index);
		draw(s, w / 2, row, col, index);
		draw(s, w / 2, row + w / 2, col, index);
		draw(s, w / 2, row + w / 2, col + w / 2, index);
	}
	else if (ch == 'f') {
		for (int i = row; i < row + w; i++) {
			for (int j = col; j < col + w; j++) {
				image[i][j] = 1;
			}
		}
	}
}

int main()
{
//	freopen("./data/f/1.in", "r", stdin);
	
	int t; scanf("%d", &t);
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;
		memset(image, 0, sizeof(image));
		int index1 = 0;
		int index2 = 0;
		draw(s1, 32, 0, 0, index1);
		draw(s2, 32, 0, 0, index2);
		cnt = 0;
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (image[i][j]) cnt++;
			}
		}
		printf("There are %d black pixels.\n", cnt);
	}
	
	return 0;
}
