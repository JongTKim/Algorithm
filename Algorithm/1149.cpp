#include<bits/stdc++.h>
using namespace std;

// 2024.04.22
// Writen by JongTKim

// 푼 방법 : DP

int cost[3];
int dp[1001][3];
int fm = 10000000;

int main() {
	int N;
	cin >> N; 

	dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;

	for (int i = 1; i <=N; i++) 
	{
		cin >> cost[0] >> cost[1] >> cost[2];
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[2];
	}
	cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
	return 0;
}

/* 처음 풀이
#include<bits/stdc++.h>
using namespace std;

int arr[1001][3];
int dp[1001][3];
int fm = 10000000;

int main() {
	int N;
	cin >> N; 
	fill(&dp[0][0], &dp[1000][3], -1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j == k) continue;
				dp[i + 1][k] != -1 ? dp[i + 1][k] = min(dp[i][j] + arr[i + 1][k], dp[i + 1][k]) : dp[i + 1][k] = dp[i][j] + arr[i + 1][k];				
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		fm = min(fm, dp[N - 1][i]);
	}
	cout << fm << "\n";
	return 0;
}
*/