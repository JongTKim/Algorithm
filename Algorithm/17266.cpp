#include<bits/stdc++.h>
using namespace std;

// 2024.06.02
// Written by JongTKim

// Ǭ ��� : ����

int N, M, maxn;
int prevv, pos; // �������� ������� ��´�

void input() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
}

int main() {
	input();
	cin >> N >> M >> prevv;
	maxn = prevv; // ó������ ���ε� �ϳ��ۿ� ��ġ�� ���Ѵ�.
	for (int i = 0; i < M-1; i++) {
		cin >> pos;
		maxn = max(maxn, (pos - prevv + 1) / 2); // �߰����� ���ε� �ΰ��� ��ĥ�� �ִ�.
		prevv = pos;
	}
	maxn = max(maxn, N - prevv); // ���������� ���ε� �ϳ��ۿ� ��ġ�� ���Ѵ�
	cout << maxn << "\n";
	return 0;
}