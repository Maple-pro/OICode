// WA
#include <bits/stdc++.h>
using namespace std;

set<string> words;

int main()
{
	string s;
	while (cin >> s) words.insert(s);
	
	set<string>::iterator it;
	for (it = words.begin(); it != words.end(); it++) {
		string tmp = *it;
		int len = tmp.size();
		for (int i = 1; i < len-1; i++) {
			if (words.count(tmp.substr(0, i)) && words.count(tmp.substr(i, len-i))) {
				cout << tmp << endl;
			}
		}
	}
	return 0;
}
