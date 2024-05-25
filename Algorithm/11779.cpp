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

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {�Ѻ��, ������}�� ��

	pq.push({ 0, start }); // ��������� ���, ��������

	d[start] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int loc = pq.top().second;
		
		pq.pop();

		if (d[loc] < cost) continue;

		for (pair<int, int> p : graph[loc]) { // p.first -> ��������, p.second -> ���µ� ���
			if (cost + p.second < d[p.first]) { // �̰� �������� �ϳ��� �� �鸮�°Ŵϱ�
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
	cin >> ss >> ee; // ss�� ��ߵ���, ee�� ��������
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	input(); // �Է�

	fill(&d[0], &d[N + 1], inf); // ���ͽ�Ʈ�� ����ġ �ʱ�ȭ

	dijkstra(ss); // ���� ss -> ee������ �ּ� ����� ���´�.

	cout << d[ee] << "\n";

	while (ee) { // ��Ʈ��ŷ
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