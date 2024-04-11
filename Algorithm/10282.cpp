#include<bits/stdc++.h>
using namespace std;

// 2024.04.11
// Writen by JongTKim

// Ǭ ��� : ���ͽ�Ʈ��
int tc; 
const int inf = 1e9;
int ds[10005]; // ����ġ �迭

void dijkstra(int start, vector<pair<int,int>> graph[]) {

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {�Ѻ��, ������}�� ��

	pq.push({ 0,start }); 
	ds[start] = 0; // ���� ��� ��� 0���� �ʱ�ȭ

	while (!pq.empty())
	{
		int dist = pq.top().first; // ���� �������� ���
		int loc = pq.top().second; // ���� ��� ��ȣ
		pq.pop();

		if (ds[loc] < dist)
			continue;

		for (int i = 0; i < graph[loc].size(); i++) { // ���� ��ο��� �� �� �ִ� ���� Ž��
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
			graph[b].push_back({ a,s }); // 2���� 1�� �����ϰ� ��� 5�̸� graph[1]�� {2,5}�� ����.
		}


		fill(ds, ds + n + 1, inf); // �ִ����� �ʱ�ȭ

		dijkstra(c, graph);

		for (int i = 0; i <=  n; i++) {
			if (ds[i] != inf) { // �� �� �ִ� ��Ҷ��
				cnt++;
				maxn = max(maxn, ds[i]);
			}
		}
		cout << cnt << " " << maxn << "\n";

	}
	return 0;
}