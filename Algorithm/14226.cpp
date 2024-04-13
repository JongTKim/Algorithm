#include<bits/stdc++.h>
using namespace std;

// 2024.04.13
// Writen by JongTKim

// Ǭ ��� : BFS
int S;
bool dp[1001][1001]; // visited�� üũ�ϴ� �迭. ���� ���� ������ 2���̰�, Ŭ������ 2���϶��� dp[2][2]=true ó��
int mina;


typedef struct Info {
	int num; // ���� �� ���� ���������
	int clip; // Ŭ�����忡 � ���ִ���
	int t; // ���� �ð��� ��������
	Info(int Num, int Clip, int T) : num(Num), clip(Clip), t(T) {}
};

void bfs() {
	queue<Info> q;
	q.push(Info(1, 1, 1)); // ó���� Ŭ�����忡 ��°��(1��)�� �ߴ� �����ϰ� ����

	while (!q.empty()) {
		int num = q.front().num;
		int cnum = q.front().clip;
		int t = q.front().t;

		q.pop();

		if (num <= 0) continue; // 0���ϸ� �ö�ü� �ִ� ����� X, 0�ε� Ŭ�����忡 10���� �������� ��ؿ�? -> �׷��� 10���� �ٽ� ������������, ���ʿ� �׷��� �� ���� ����

		if (num < cnum) continue;

		if (num == S) { // ����, ���ϴ� ������ �����ϸ� �׶��� �ð��� ��� break, BFS�ϱ� �� �ð��� ���� ���ü�������
			mina = t;
			break;
		}

		dp[num][cnum] = true;

		if (num <= 1000) { // ** ������ �� �����غ��°��� �߿���
			if (!dp[num][num]) q.push(Info(num, num, t + 1)); // ����(1��)
			if (!dp[num - 1][cnum]) q.push(Info(num - 1, cnum, t + 1)); // ����(3��)
		}
		if (num + cnum <= 1000) {
			if (!dp[num + cnum][cnum]) q.push(Info(num + cnum, cnum, t + 1)); // �ٿ��ֱ�(2��)
		}
	}
}
int main() {

	cin >> S;

	bfs();

	cout << mina << "\n";

	return 0;
}