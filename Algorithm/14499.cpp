#include<bits/stdc++.h>
using namespace std;

// 2024.04.05
// Writen by JongTKim
// 푼 방법 : 구현, 시뮬레이션

int arr[21][21]; // Map
int kn[1001]; // 명령의 개수
int a1, a2, a3, a4, a5, a6; // 주사위를 나타냄 a1 밑, a2 앞, a3 위, a4 뒤, a5 좌, a6 우
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
	cin >> N >> M >> y >> x >> k; // y,x를 바꿔서 받는게 핵심
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
		case 1: // 동쪽
			if (nowx + 1 < M) {
				tmp = a1; a1 = a6; a6 = a3; a3 = a5; a5 = tmp;
				nowx += 1; // 주의점 : overflow를 먼저 판단하고 위치를 갱신해줘야함
				solve(nowy, nowx);
				print();
			}
			break;
		case 2: // 서쪽
			if (nowx - 1 >= 0) {
				tmp = a1; a1 = a5; a5 = a3; a3 = a6; a6 = tmp;
				nowx -= 1;
				solve(nowy, nowx);
				print();
			}
			break;
		case 3: // 북쪽
			if (nowy - 1 >= 0) {
				tmp = a1; a1 = a4; a4 = a3; a3 = a2; a2 = tmp;
				nowy -= 1;
				solve(nowy, nowx);
				print();
			}
			break;
		case 4: // 남쪽
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