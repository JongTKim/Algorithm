#include<bits/stdc++.h>
using namespace std;

// 2024.05.12
// Written by JongTKim

// 푼 방법 : 브루트포스, 백트래킹, 조합

int N;
int arr[25][25];
bool visited[25];
int mmin = 1e9;

void dfs(int depth, int idx) {
	if (depth == N / 2) { // 절반 한팀만들었음
		int team1 = 0, team2 = 0;
		for (int j = 1; j <= N; j++) { // 절반팀의 합을 구해주자
			for (int k = j + 1; k <= N; k++) {
				if (visited[j] && visited[k]) team1 += (arr[j][k] + arr[k][j]);
				else if (!visited[j] && !visited[k]) team2 += (arr[j][k] + arr[k][j]);
			}
		}
		mmin = min(mmin, abs(team1 - team2));
		return;
	}
	for (int i = idx; i <= N; i++)
	{
		visited[i] = true;
		dfs(depth + 1, i + 1);
		visited[i] = false;

	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> arr[i][j];
	}

	dfs(0, 1);
	cout << mmin << "\n";
	return 0;
}