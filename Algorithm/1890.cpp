#include<bits/stdc++.h>
using namespace std;


// 2024.04.10	
// Writen by JongTKim

// Ǭ ��� : DFS+DP, DP

int N;
int arr[101][101];
long long dp[101][101];


// ����, DFS+DP�� ������ DP�迭�� ��� ��Ҹ� -1���� �ʱ�ȭ�ϰ� �ؾ� �ߺ��� �����Ҽ�����
// -1�� �ʱ�ȭ ���� �ʴ��� ���� ���Ҽ� ����, ������ �ߺ��� ��ҵ� ó���ϱ� ������ �ð��� ����
// DFS �ʱ��������� count++ �ϸ鼭 ����غ��� ���� ���̸� Ȯ���� �� ����.
long long dfs(int y, int x) {
	if (y == N - 1 && x == N - 1) return 1;

	if (arr[y][x] == 0) return 0;

	if (dp[y][x] == -1) { // ó������ ���̶��
		dp[y][x] = 0;
		int ny = y + arr[y][x];
		int nx = x + arr[y][x];

		if (ny < N) dp[y][x] += dfs(ny, x);
		if (nx < N) dp[y][x] += dfs(y, nx);
	}
	return dp[y][x];
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	// DP ����

	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] && arr[i][j] > 0) {
				int num = arr[i][j];
				if (i + num < N) dp[i + num][j] += dp[i][j];
				if (j + num < N) dp[i][j + num] += dp[i][j];
			}

		}
	}

	cout << dp[N - 1][N - 1] << "\n";

	// DP ��


	// DFS+DP ����(���� DFS+DP�� ����ϰ� �ʹٸ� ���� ��¹��� �ּ�ó���ϰ� �� �ڵ带 ����ϸ��.)

	/* memset(dp, -1, sizeof(dp))
	cout << dfs(0, 0) << "\n";*/

	// DFS+DP ��

	return 0;
}