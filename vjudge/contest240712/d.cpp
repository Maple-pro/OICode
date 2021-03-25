#include <bits/stdc++.h>
using namespace std;

vector<string> words;
vector<string> ans;
map<string, int> cnt;

string stand(string s) {
	string tmp = s;
	for (int i = 0; i < tmp.size(); i++) {
		tmp[i] = tolower(tmp[i]);
	}
	sort(tmp.begin(), tmp.end());
	return tmp;
}

int main()
{
	string s;
	while (true) {
		cin >> s;
		if (s == "#") break;
		words.push_back(s);
		string s1 = stand(s);
		if (cnt.count(s1) == 0) cnt[s1] = 0;
		cnt[s1]++;
	}
	
	for (int i = 0; i < words.size(); i++) {
		if (cnt[stand(words[i])] <= 1) ans.push_back(words[i]);
	}
	sort(ans.begin(), ans.end());
	
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
