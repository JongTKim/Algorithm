#include<bits/stdc++.h>
using namespace std;

// 푼 방법 : DFS+DP

int M, N;
int arr[501][501];
int dp[501][501];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int dfs(int y, int x) {
	if (y == M - 1 && x == N - 1)
		return 1;

	if (dp[y][x] == -1) { // 처음가는 곳이라면
		dp[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue; // overflow	
			if (arr[ny][nx] < arr[y][x]) dp[y][x] += dfs(ny, nx);
		}
	}
	return dp[y][x];
}
int main() {

		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		cin >> M >> N;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 0) << "\n";
	return 0;
}