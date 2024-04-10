#include<bits/stdc++.h>
using namespace std;


// 2024.04.10	
// Writen by JongTKim

// 푼 방법 : DFS+DP, DP

int N;
int arr[101][101];
long long dp[101][101];


// 만약, DFS+DP를 쓰려면 DP배열의 모든 요소를 -1으로 초기화하고 해야 중복을 제거할수있음
// -1를 초기화 하지 않더라도 답을 구할순 있음, 하지만 중복된 요소도 처리하기 때문에 시간이 더들어감
// DFS 초기조건으로 count++ 하면서 계산해보면 둘의 차이를 확인할 수 있음.
long long dfs(int y, int x) {
	if (y == N - 1 && x == N - 1) return 1;

	if (arr[y][x] == 0) return 0;

	if (dp[y][x] == -1) { // 처음가는 곳이라면
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

	// DP 시작

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

	// DP 끝


	// DFS+DP 시작(만약 DFS+DP를 사용하고 싶다면 위의 출력문을 주석처리하고 이 코드를 사용하면됨.)

	/* memset(dp, -1, sizeof(dp))
	cout << dfs(0, 0) << "\n";*/

	// DFS+DP 끝

	return 0;
}