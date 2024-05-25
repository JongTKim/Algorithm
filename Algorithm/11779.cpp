#include<bits/stdc++.h>
#define inf 1e9
using namespace std;

int N, M;
int st, en, ga;
int ss, ee;
int d[1005], route[1005];
vector<pair<int, int>> graph[1005];
stack<int> f_route;

void dijkstra(int start) {

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {총비용, 현재노드}가 들어감

	pq.push({ 0, start }); // 현재까지의 비용, 현재지점

	d[start] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int loc = pq.top().second;
		
		pq.pop();

		if (d[loc] < cost) continue;

		for (pair<int, int> p : graph[loc]) { // p.first -> 다음지점, p.second -> 가는데 비용
			if (cost + p.second < d[p.first]) { // 이게 들어갈때마다 하나씩 더 들리는거니깐
				d[p.first] = cost + p.second;
				route[p.first] = loc;
				pq.push({ cost + p.second, p.first }); 
			}
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> st >> en >> ga;
		graph[st].push_back({ en,ga });
	}
	cin >> ss >> ee; // ss는 출발도시, ee는 도착도시
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	input(); // 입력

	fill(&d[0], &d[N + 1], inf); // 다익스트라 가중치 초기화

	dijkstra(ss); // 이후 ss -> ee까지의 최소 비용이 나온다.

	cout << d[ee] << "\n";

	while (ee) { // 백트래킹
		f_route.push(ee);
		ee = route[ee];
	}

	cout << f_route.size() << "\n";

	while (!f_route.empty()) {
		cout << f_route.top() << " ";
		f_route.pop();
	}

	return 0;
}