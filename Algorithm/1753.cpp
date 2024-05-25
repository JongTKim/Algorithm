#include<bits/stdc++.h>
#define inf 1e9
using namespace std;



int V, E, K;
int A, B, T;
vector<pair<int, int>> vec[20001];
int d[20001];

void dijkstra(int start) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {총비용, 현재노드}가 들어감

	pq.push({ 0,start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;
		int loc = pq.top().second;

		pq.pop();

		if (d[loc] < dist) continue; // 누가 이미 최단거리를 바꿔놨을지도 모르니깐

		for (pair<int, int> p : vec[loc]) { // 현재 위치에서 갈수있는곳이 어디있을까?
			if (dist + p.second < d[p.first]) {
				d[p.first] = dist + p.second;
				pq.push({ dist + p.second, p.first });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V >> E >> K;
	for(int i=0; i< E; i++){
		cin >> A >> B >> T;
		vec[A].push_back({ B,T });
		// A 정점에는 B가 연결되어있고 거리는 T이다.
	}

	fill(d, d + V + 1, inf); // 다익스트라를 위해 최대값으로 초기화
	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (d[i] == inf) cout << "INF" << "\n";
		else cout << d[i] << "\n";
	}

	return 0;
}