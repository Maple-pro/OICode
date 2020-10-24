// priority queue, greedy
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;
typedef struct {
	int dist;
	int amount;
} stop;
stop stops[maxn];

bool comp(stop s1, stop s2)
{
	return s1.dist < s2.dist;
}

int main()
{
	ios::sync_with_stdio(false);
	int ans = 0;
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> stops[i].dist >> stops[i].amount;
	}
	int L, P;
	cin >> L >> P;
	
	for (int i = 0; i < N; i++) stops[i].dist = L - stops[i].dist;
	
	stops[N].dist = L;
	stops[N].amount = 0;
	N++;
	sort(stops, stops + N, comp);
	
	priority_queue<int> que;
	int pos = 0; // Now position
	int tank = P; // Now fuel in car
	for (int i = 0; i < N; i++)
	{
		int d = stops[i].dist - pos;
		while (tank < d)
		{
			if (que.empty())
			{
				puts("-1");
				return 0;
			}
			else
			{
				tank += que.top();
				que.pop();
				ans++;
			}
		}
		tank -= d;
		pos = stops[i].dist;
		que.push(stops[i].amount);
	}
	cout << ans << endl;
	return 0;
}
