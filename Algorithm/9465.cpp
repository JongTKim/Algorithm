#include<bits/stdc++.h>
using namespace std;

// 2024.04.20
// Writen by JongTKim

// 푼 방법 : DP

int arr[2][100001];
int dp[2][100001];

int main() {
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) cin >> arr[i][j];
		}

		memset(dp, 0, sizeof(dp));

		dp[0][0] = arr[0][0]; dp[1][0] = arr[1][0];

		for (int i = 0; i < n-1; i ++) { // 4일때는 2만 5일때는 2,4까지가게
			for (int j = 0; j < 2; j++) {
				if (j == 1) {
					dp[0][i + 1] = max(dp[0][i + 1], dp[1][i] + arr[0][i + 1]);
					dp[0][i + 2] = max(dp[0][i + 2], dp[1][i] + arr[0][i + 2]);
				}
				if (j == 0) {
					dp[1][i + 1] = max(dp[1][i + 1], dp[0][i] + arr[1][i + 1]);
					dp[1][i + 2] = max(dp[1][i + 2], dp[0][i] + arr[1][i + 2]);
				}
			}
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
	}
	return 0;
}