#include<bits/stdc++.h>
using namespace std;

// 2024.04.22
// Writen by JongTKim

// Ç¬ ¹æ¹ý : DP

int arr[501][501];
int dp[501][501];
int msum;

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) cin >> arr[i][j];
	}
	
	dp[0][0] = arr[0][0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + arr[i + 1][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + arr[i + 1][j + 1]);
		}
	}

	for (int i = 0; i < n; i++) {
		msum = max(msum, dp[n - 1][i]);
	}

	cout << msum << "\n";

	return 0;
}