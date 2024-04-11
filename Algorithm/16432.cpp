#include<bits/stdc++.h>
using namespace std;

// 2024.04.11
// Writen by JongTKim

// 푼 방법 : DFS + DP
int N, cnum, dnum;
int dp[1001][10]; // DP 배열
vector<int> vec[1001];
stack<int> q;
int flag;

void dfs(int day, int num) { // day는 그날, num은 떡번호

	if (dp[day][num]) // 만약 이미 방문된 곳이라면
		return;

	if (day == N) { // 떡을 주는데 성공한경우
		stack<int> q2;
		while (!q.empty()) {
			q2.push(q.top());
			q.pop();
		}
		while (!q2.empty()) {
			cout << q2.top() << "\n";
			q2.pop();
		}
		exit(0);
	}

	for (int nextnum : vec[day]) {
		if (nextnum != num) { // 다음날 떡번호는 오늘 떡번호랑 달라야함
			q.push(nextnum);
			dfs(day + 1, nextnum);
			q.pop(); //  답을 찾지 못했을경우 pop
		}
	}
	dp[day][num] = 1;

}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> dnum; // 떡 개수
		for (int j = 0; j < dnum; j++) {
			cin >> cnum; // 떡 번호
			vec[i].push_back(cnum);
		}
	}
	dfs(0, 0);

	cout << -1 << "\n";
	return 0;
}