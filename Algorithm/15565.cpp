#include<bits/stdc++.h>
using namespace std;

// 2024.05.26
// Written by JongTKim

// Ǭ ��� : ��������, ť

int N, K;
int mmin = 1<<20;
int cnt, arr[1000001];

/* �������� Ǯ�� */
void solve1() {
	for (int i = 0; i < N; i++) cin >> arr[i];
	int start = 0, end = 0; // �������� ����ְ�
	while (end <= N) {
		if (cnt < K) { // ���� K���� ���̾��� ���̾������� end�� ��� �÷������
			if (arr[end] == 1) cnt++;
			end++;
		}
		else if (cnt == K) { // K���� ���̾��� ã�Ҵٸ� ���� ����ȭ�� �����ؾ���
			mmin = min(mmin, end - start);
			while (cnt > K - 2) {
				if (arr[start] == 1) cnt--;
				start++;
			}
			start--;
			cnt++;
		}
	}
}

/* ť�� �̿��� �����̵� ������ */
void solve2() {
	queue<int> q;
	char num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == '1') {
			q.push(i);
			if (q.size() == K) {
				mmin = min(mmin, q.back() - q.front() + 1);
				q.pop();
			}
		}
	}
}
void input() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
}
int main() {
	input();
	//solve1();
	solve2();
	if (mmin == 1<<20) cout << -1 << "\n";
	else cout << mmin << "\n";
	return 0;
}