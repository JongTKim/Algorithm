#include<bits/stdc++.h>
using namespace std;

// 2024.04.05
// Writen by JongTKim
// Ǭ ��� : ����, �ùķ��̼�

int arr[21][21]; // Map
int kn[1001]; // ����� ����
int a1, a2, a3, a4, a5, a6; // �ֻ����� ��Ÿ�� a1 ��, a2 ��, a3 ��, a4 ��, a5 ��, a6 ��
int N, M, x, y, k;

void solve(int nowy, int nowx) {
	if (arr[nowy][nowx] == 0)
		arr[nowy][nowx] = a1;
	else {
		a1 = arr[nowy][nowx];
		arr[nowy][nowx] = 0;
	}
}

void print() {
	cout << a3 << "\n";
}

void input() {
	cin >> N >> M >> y >> x >> k; // y,x�� �ٲ㼭 �޴°� �ٽ�
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	for (int i = 0; i < k; i++)
		cin >> kn[i];
}

int main() {
	input();
	int nowy = y;
	int nowx = x;
	for (int i = 0; i < k; i++) {
		int tmp;
		switch (kn[i]) {
		case 1: // ����
			if (nowx + 1 < M) {
				tmp = a1; a1 = a6; a6 = a3; a3 = a5; a5 = tmp;
				nowx += 1; // ������ : overflow�� ���� �Ǵ��ϰ� ��ġ�� �����������
				solve(nowy, nowx);
				print();
			}
			break;
		case 2: // ����
			if (nowx - 1 >= 0) {
				tmp = a1; a1 = a5; a5 = a3; a3 = a6; a6 = tmp;
				nowx -= 1;
				solve(nowy, nowx);
				print();
			}
			break;
		case 3: // ����
			if (nowy - 1 >= 0) {
				tmp = a1; a1 = a4; a4 = a3; a3 = a2; a2 = tmp;
				nowy -= 1;
				solve(nowy, nowx);
				print();
			}
			break;
		case 4: // ����
			if (nowy + 1 < N) {
				tmp = a1; a1 = a2; a2 = a3; a3 = a4; a4 = tmp;
				nowy += 1;
				solve(nowy, nowx);
				print();
			}
			break;
		}
	}
	return 0;
}