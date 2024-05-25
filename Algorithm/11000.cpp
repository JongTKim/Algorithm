#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;
int N, cnt;
pr p[200001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> p[i].first >> p[i].second;
	}

	sort(p, p + N);

	priority_queue<int, vector<int>, greater<int>> pq;

	pq.push(p[0].second); // 3��

	for (int i = 1; i < N; i++) {
		if (p[i].first < pq.top()) { // ���� �������ϴ°��
			cnt++;
			pq.push(p[i].second);
		}
		else { // �׳� �״�� �����ִ°��
			pq.pop();
			pq.push(p[i].second);
		}
	}

	cout << cnt+1 << "\n";
	
	
	return 0;
}