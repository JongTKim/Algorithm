#include<bits/stdc++.h>
using namespace std;

// 2024.05.07
// Written by JongTKim

// Ǭ ��� : ����, ��������

int N, arr[11];
int visited[11];

void solve1() {
	deque<int> dq;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = N; i >= 1; i--) {
		if (!arr[i]) dq.push_front(i);
		else dq.insert(dq.begin() + arr[i], i);
	}
	for (int n : dq) cout << n << " ";
}

void solve2() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[j] || visited[j]) continue; // ���� ������ 0�� �ƴϰų� ���ϸ� X
			cout << j << " ";
			visited[j] = 1;
			for (int k = 0; k < j; k++) arr[k]--;
			break;
		}
	}
}
int main() {
	//solve1();
	solve2();
	return 0;
}