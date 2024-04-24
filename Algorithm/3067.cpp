#include<bits/stdc++.h>
using namespace std;

// 2024.04.24
// Written by JongTKim

// Ç¬ ¹æ¹ý : DP(Knapsack)

int T, N, M;
int cost[21];
int dp[10001];

int main() {
	cin >> T;
	
	while (T--) {
		cin >> N;
		memset(dp, 0, sizeof(dp));
		for(int i=0; i<N; i++){
			cin >> cost[i];
;		}
		cin >> M;

		dp[0] = 1;

		for (int i = 0; i < N; i++) {
			for (int j = cost[i]; j <= M; j++) {
				dp[j] += dp[j - cost[i]];
			}
		}

		cout << dp[M] << "\n";
	}
	return 0;
}