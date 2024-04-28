#include<bits/stdc++.h>
#define inf 1e9
using namespace std;

// 2024.04.28
// Writen by JongTKim

// Ǭ ��� : ����� ���ͽ�Ʈ��
// �ڡ��߿�ڡ�

int N, M, X;
int A, B, T;
int d[2][1005];
vector<pair<int, int>> graph[2][1005]; 
int mmax;


void dijkstra(int start, int flag) {

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {�Ѻ��, ������}�� ��

	pq.push({ 0,start });
	d[flag][start] = 0;

	while (!pq.empty())	{
		int dist = pq.top().first; // ���� �������� ���
		int loc = pq.top().second; // ���� ���

		pq.pop();

		if (d[flag][loc] < dist) continue;
		
		for (pair<int, int> p : graph[flag][loc]) {
			if (dist + p.second < d[flag][p.first]) { // ���� ������ ���� �ּҰ�κ��� ª�ٸ�
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
		graph[0][A].push_back({ B,T }); // ������ �׷���
		graph[1][B].push_back({ A,T }); // ������ �׷���
	}
	
	fill(&d[0][0], &d[0][N + 1], inf);
	fill(&d[1][0], &d[1][N + 1], inf);

	dijkstra(X, 0); // �������� X���� �� ���������� �ִܽð��� ���Ѵ�
	dijkstra(X, 1); // ������
	

	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		mmax = max(d[0][i] + d[1][i], mmax);
	}

	cout << mmax << "\n";

	return 0;
}