#include<bits/stdc++.h>
using namespace std;

int main() {

	int T, N, K;

	cin >> T;
	while (T--) {
		vector<int> vec[1004];
		int tim[1004]; // �Ǽ� �ð�
		int degree[1004] = { 0 }; // ����
		int ga[1004] = { 0 }; // �ʿ��� �Ǽ� �ð�(����ġ)

		int x, y, W;

		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> tim[i];
		}
		for (int j = 0; j < K; j++) {
			cin >> x >> y;
			vec[x].push_back(y);
			degree[y]++;
		}
		cin >> W;
		// �Է¿Ϸ�

		queue<int> q;

		for (int i = 1; i <= N; i++) {
			if (!degree[i]) q.push(i); // ����, ���� ���� �������ִ� �ǹ����� �ٷ� ����
		}

		while (!q.empty()) {
			int build = q.front(); // ���� ���� �ǹ��� ��ȣ�� ��

			q.pop();

			for (int i : vec[build]) { // ���� �ǹ��� ����� ������ �ִ� �ǹ����� ��ȣ
				degree[i]--;
				ga[i] = max(ga[i], ga[build] + tim[build]); 
				// �ٽ��ڵ�. ���� �ǹ��� ����ġ�� ���� �ǹ��� ����ġ+����ð�
				if (degree[i] == 0) {
					q.push(i);
				}
			}
		}

		cout << ga[W] + tim[W] << "\n";
	}
	return 0;
}