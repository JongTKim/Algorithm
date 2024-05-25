#include<bits/stdc++.h>
#define inf 1e9
using namespace std;



int V, E, K;
int A, B, T;
vector<pair<int, int>> vec[20001];
int d[20001];

void dijkstra(int start) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {�Ѻ��, ������}�� ��

	pq.push({ 0,start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;
		int loc = pq.top().second;

		pq.pop();

		if (d[loc] < dist) continue; // ���� �̹� �ִܰŸ��� �ٲ�������� �𸣴ϱ�

		for (pair<int, int> p : vec[loc]) { // ���� ��ġ���� �����ִ°��� ���������?
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
		// A �������� B�� ����Ǿ��ְ� �Ÿ��� T�̴�.
	}

	fill(d, d + V + 1, inf); // ���ͽ�Ʈ�� ���� �ִ밪���� �ʱ�ȭ
	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (d[i] == inf) cout << "INF" << "\n";
		else cout << d[i] << "\n";
	}

	return 0;
}