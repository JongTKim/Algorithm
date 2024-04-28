#include<bits/stdc++.h>
#define inf 1e9
using namespace std;

// 2024.04.28
// Writen by JongTKim

// 푼 방법 : 양방향 다익스트라
// ★★중요★★

int N, M, X;
int A, B, T;
int d[2][1005];
vector<pair<int, int>> graph[2][1005]; 
int mmax;


void dijkstra(int start, int flag) {

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {총비용, 현재노드}가 들어감

	pq.push({ 0,start });
	d[flag][start] = 0;

	while (!pq.empty())	{
		int dist = pq.top().first; // 현재 노드까지의 비용
		int loc = pq.top().second; // 현재 노드

		pq.pop();

		if (d[flag][loc] < dist) continue;
		
		for (pair<int, int> p : graph[flag][loc]) {
			if (dist + p.second < d[flag][p.first]) { // 만약 가려는 곳의 최소경로보다 짧다면
				d[flag][p.first] = dist+p.second;
				pq.push({ dist + p.second, p.first });
			}
		}

	}
}


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> T;
		graph[0][A].push_back({ B,T }); // 정방향 그래프
		graph[1][B].push_back({ A,T }); // 역방향 그래프
	}
	
	fill(&d[0][0], &d[0][N + 1], inf);
	fill(&d[1][0], &d[1][N + 1], inf);

	dijkstra(X, 0); // 정방향은 X에서 각 정점까지의 최단시간을 구한다
	dijkstra(X, 1); // 역방향
	

	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		mmax = max(d[0][i] + d[1][i], mmax);
	}

	cout << mmax << "\n";

	return 0;
}