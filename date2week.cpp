#include <bits/stdc++.h>
using namespace std;

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
int total = 0;

bool isrun(int y)
{	
	if ((y % 4 == 0) && ((y % 100 == 0 && y % 400 == 0) || y % 100 != 0)) return true;
	else return false;
}

int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    if (m > 12 || m <= 0 || d <= 0 || d > month[m - 1]) {
    	if (isrun(y) && m == 2 && d == 29) {
    		
		}
		else {
			cout << "error" << endl;
    		return 0;
		}
	}
    int dy, dm, dd;
    dy = y - 2000;
    dm = m;
    dd = d;
    int runNum = 0;
    for (int i = 2000; i < y; i++) {
    	if (isrun(i)) runNum++;
	}
    total += dy * 365 + runNum;
    for (int i = 1; i < m; i++) {
    	if (isrun(y) && i == 2) total++;
    	total += month[i - 1];
	}
    total += dd;

    int res = total % 7; 
    cout << res << endl;

    return 0;
}
