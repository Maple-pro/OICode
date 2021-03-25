#include <bits/stdc++.h>
using namespace std;

set<string> dict; 

int main()
{
	string s, buf;
	while (cin >> s) {
		for (int i = 0; i < s.size(); i++) {
			if (isalpha(s[i])) s[i] = tolower(s[i]);
			else s[i] = ' ';
		}
//		cout << s << endl;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ') {
				buf.push_back(s[i]);
			}
			else {
				if (!buf.empty()) dict.insert(buf);
				buf.clear();
			}
		}
		if (!buf.empty()) dict.insert(buf); 
//		cout << buf << endl;
		buf.clear();
	}
	set<string>::iterator it;

	for (it = dict.begin(); it != dict.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
