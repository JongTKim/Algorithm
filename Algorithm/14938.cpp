#include<bits/stdc++.h>
#define inf 1e9
using namespace std;

// 2024.05.23
// Written by JongTKim

// 푼 방법 : 다익스트라, 플로이드 워셜

int N, M, R; // 노드의개수, 수색범위, 간선의 개수
int A, B, L;
int arr[101]; // 각 지역에 있는 아이템의 수
vector<pair<int, int>> vec[101];
int sum, msum;
int d[101];

void dijkstra(int start) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {총비용, 현재노드}가 들어감
	fill(d, d + 101, inf);
	sum = 0;
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
	// 여기까지 끝났으면 모든 지점과의 거리가 완료된 상태
	for (int i = 1; i <= N; i++) {
		if (d[i] <= M) sum += arr[i];
	}

	msum = max(msum, sum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++) cin >> arr[i];

	for (int i = 1; i <= R; i++) {
		cin >> A >> B >> L;
		vec[A].push_back({ B,L }); // A 정점에는 B가 연결되어있고 거리는 L이다.
		vec[B].push_back({ A,L }); // 양방향이니깐 양쪽으로 넣어준다.
	}

	for (int i = 1; i <= N; i++) dijkstra(i);

	cout << msum << "\n";
	return 0;
}