#include<bits/stdc++.h>
using namespace std;

// 2024.04.11
// Writen by JongTKim

// 푼 방법 : 다익스트라
int tc; 
const int inf = 1e9;
int ds[10005]; // 가중치 배열

void dijkstra(int start, vector<pair<int,int>> graph[]) {

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {총비용, 현재노드}가 들어감

	pq.push({ 0,start }); 
	ds[start] = 0; // 시작 노드 비용 0으로 초기화

	while (!pq.empty())
	{
		int dist = pq.top().first; // 현재 노드까지의 비용
		int loc = pq.top().second; // 현재 노드 번호
		pq.pop();

		if (ds[loc] < dist)
			continue;

		for (int i = 0; i < graph[loc].size(); i++) { // 현재 경로에서 갈 수 있는 지점 탐색
			if (dist + graph[loc][i].second < ds[graph[loc][i].first]) {
				ds[graph[loc][i].first] = dist + graph[loc][i].second;
				pq.push({ dist + graph[loc][i].second, graph[loc][i].first });
			}
		}

	}
}

int main() {
	cin >> tc;
	while (tc--) {

		int n, d, c;
		int a, b, s;
		vector<pair<int, int>> graph[10005];

		int cnt = 0;
		int maxn = 0;

		cin >> n >> d >> c;
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			graph[b].push_back({ a,s }); // 2번이 1을 의존하고 비용 5이면 graph[1]에 {2,5}로 들어간다.
		}


		fill(ds, ds + n + 1, inf); // 최댓값으로 초기화

		dijkstra(c, graph);

		for (int i = 0; i <=  n; i++) {
			if (ds[i] != inf) { // 갈 수 있는 장소라면
				cnt++;
				maxn = max(maxn, ds[i]);
			}
		}
		cout << cnt << " " << maxn << "\n";

	}
	return 0;
}