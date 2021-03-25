// 贪心，优先队列 
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> events = {
	{1, 2}, {2, 3}, {3, 4}, {1, 2}
};
const int maxn = 1e5 + 5;
vector<int> startday[maxn];
vector<int> endday[maxn];
priority_queue<int, vector<int>, greater<int>> pq;

int maxEvents() {
	int minday = maxn;
    int maxday = 0;
    int len = events.size();
    for (int i = 0; i < len; i++) {
        startday[events[i][0]].push_back(i);
        endday[events[i][1]].push_back(i);
        minday = min(minday, events[i][0]);
        maxday = max(maxday, events[i][1]);
    }
    
    int ans = 0;
    
    for (int i = minday; i <= maxday; i++) {
        for (int j = 0; j < startday[i].size(); j++) {
            pq.push(events[startday[i][j]][1]);
        }
        if (!pq.empty()) {
            ans++;
            pq.pop();
        }
        while (!pq.empty() && pq.top() <= i) {
        	pq.pop();
		}
    }
    
    return ans;
}

int main()
{
	int ans = maxEvents();
	cout << ans << endl;
	return 0;
}
