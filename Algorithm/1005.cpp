#include<bits/stdc++.h>
using namespace std;

int main() {

	int T, N, K;

	cin >> T;
	while (T--) {
		vector<int> vec[1004];
		int tim[1004]; // 건설 시간
		int degree[1004] = { 0 }; // 위상
		int ga[1004] = { 0 }; // 필요한 건설 시간(가중치)

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
		// 입력완료

		queue<int> q;

		for (int i = 1; i <= N; i++) {
			if (!degree[i]) q.push(i); // 만약, 지금 당장 지을수있는 건물들은 바로 짓기
		}

		while (!q.empty()) {
			int build = q.front(); // 현재 지을 건물의 번호가 들어감

			q.pop();

			for (int i : vec[build]) { // 현재 건물을 지어야 지을수 있는 건물들의 번호
				degree[i]--;
				ga[i] = max(ga[i], ga[build] + tim[build]); 
				// 핵심코드. 다음 건물의 가중치는 현재 건물의 가중치+건축시간
				if (degree[i] == 0) {
					q.push(i);
				}
			}
		}

		cout << ga[W] + tim[W] << "\n";
	}
	return 0;
}