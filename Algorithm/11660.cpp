#include<bits/stdc++.h>
using namespace std;

// 2024.04.25
// Writen by JongTKim

// Ǭ ��� : ������

int N, M;
int psum[1050000];
int xf, xs, yf, ys;
int num;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N * N; i++) {
		cin >> num;
		psum[i + 1] = psum[i] + num;
	}
	for (int i = 0; i < M; i++) {
		cin >> yf >> xf >> ys >> xs;
		int fsum = 0;
		for (int j = yf; j <= ys; j++) { // y���� ���� �ݺ�Ƚ���� ��Ÿ����.
			fsum += (psum[N * (j - 1) + xs] - psum[N * (j - 1) + (xf - 1)]);
		}
		cout << fsum << "\n";
	}
	return 0;
}