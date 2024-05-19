#include<bits/stdc++.h>
using namespace std;

// 2024.05.19
// Written by JongTKim

// 푼 방법 : DP

int N, M, num;
int arr[1001][1001];
int dp[1001][1001][3]; // 마지막은 온 방향 
int ffmin = 100000000;


int main() {
	cin >> N >> M;
	
	for (int j = 0; j < M; j++) {
		cin >> arr[0][j];
		for (int i = 0; i < 3; i++) {
			dp[0][j][i] = arr[0][j];
		}
	}

	for (int i = 1; i < N; i++) { // y축
		for (int j = 0; j < M; j++) { // x축
			cin >> arr[i][j];

			// 0번 좌에서 왔을때, 1번 중앙으로 왔을때, 2번 우에서 왔을때
			if (j == 0) {
				dp[i][j][1] = dp[i-1][j][2] + arr[i][j];
				dp[i][j][2] = min(dp[i - 1][j+1][0], dp[i - 1][j+1][1]) + arr[i][j];
			}
			else if (j == M-1) {
				dp[i][j][0] = min(dp[i - 1][j-1][1], dp[i - 1][j-1][2]) + arr[i][j];
				dp[i][j][1] = dp[i - 1][j][0] + arr[i][j];
			}
			else {
				dp[i][j][0] = min(dp[i - 1][j-1][1], dp[i - 1][j-1][2]) + arr[i][j];
				dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + arr[i][j];
				dp[i][j][2] = min(dp[i - 1][j+1][0], dp[i - 1][j+1][1]) + arr[i][j];
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 3; j++) {
			if(dp[N-1][i][j]) ffmin = min(ffmin, dp[N-1][i][j]);
		}
	}

	cout << ffmin << "\n";
	return 0;
}