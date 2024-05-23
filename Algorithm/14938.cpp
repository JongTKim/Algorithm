#include<bits/stdc++.h>
#define inf 1e9
using namespace std;

// 2024.05.23
// Written by JongTKim

// Ǭ ��� : ���ͽ�Ʈ��, �÷��̵� ����

int N, M, R; // ����ǰ���, ��������, ������ ����
int A, B, L;
int arr[101]; // �� ������ �ִ� �������� ��
vector<pair<int, int>> vec[101];
int sum, msum;
int d[101];

void dijkstra(int start) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {�Ѻ��, ������}�� ��
	fill(d, d + 101, inf);
	sum = 0;
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
	// ������� �������� ��� �������� �Ÿ��� �Ϸ�� ����
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
		vec[A].push_back({ B,L }); // A �������� B�� ����Ǿ��ְ� �Ÿ��� L�̴�.
		vec[B].push_back({ A,L }); // ������̴ϱ� �������� �־��ش�.
	}

	for (int i = 1; i <= N; i++) dijkstra(i);

	cout << msum << "\n";
	return 0;
}