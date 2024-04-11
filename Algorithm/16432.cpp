#include<bits/stdc++.h>
using namespace std;

// 2024.04.11
// Writen by JongTKim

// Ǭ ��� : DFS + DP
int N, cnum, dnum;
int dp[1001][10]; // DP �迭
vector<int> vec[1001];
stack<int> q;
int flag;

void dfs(int day, int num) { // day�� �׳�, num�� ����ȣ

	if (dp[day][num]) // ���� �̹� �湮�� ���̶��
		return;

	if (day == N) { // ���� �ִµ� �����Ѱ��
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
		if (nextnum != num) { // ������ ����ȣ�� ���� ����ȣ�� �޶����
			q.push(nextnum);
			dfs(day + 1, nextnum);
			q.pop(); //  ���� ã�� ��������� pop
		}
	}
	dp[day][num] = 1;

}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> dnum; // �� ����
		for (int j = 0; j < dnum; j++) {
			cin >> cnum; // �� ��ȣ
			vec[i].push_back(cnum);
		}
	}
	dfs(0, 0);

	cout << -1 << "\n";
	return 0;
}