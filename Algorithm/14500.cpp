#include<bits/stdc++.h>
using namespace std;

// 2024.04.06
// Writen by JongTKim
// Ǭ ��� : ����, ����Ž��

int arr[505][505];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int fmax = 0;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	// �߿��� : �����غ���, overflow, underflow �� Ȯ���� �ʿ䰡����
	// �ֳ��ϸ�, ������ 4�� �̸��� ��ģ���� �ִ밪�� �ɼ����⶧�� 
	// ����, 1���� �����Ͽ� arr[-1][]�� �ɼ��ִ� ��츦 �������ְ�(arr[0][]�� ����) -> segmentation fault ���� ����
	// arr[505][505]�� �����Ͽ� -> undefined behavior ���� ����

	for (int y = 1; y <= N; y++) { // y�� y��
		for (int x = 1; x <= M; x++) { // x�� x��
			int mmax = 0;
			mmax = max(mmax, arr[y + 1][x] + arr[y + 2][x] + arr[y + 3][x]); // 1��
			mmax = max(mmax, arr[y][x + 1] + arr[y][x + 2] + arr[y][x + 3]); // 2��
			mmax = max(mmax, arr[y][x + 1] + arr[y + 1][x] + arr[y + 1][x + 1]); // 3��
			mmax = max(mmax, arr[y + 1][x] + arr[y + 2][x] + arr[y + 2][x + 1]); // 4��
			mmax = max(mmax, arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x]); // 5��
			mmax = max(mmax, arr[y][x + 1] + arr[y + 1][x + 1] + arr[y + 2][x + 1]); // 6��
			mmax = max(mmax, arr[y][x + 1] + arr[y][x + 2] + arr[y-1][x + 2]); // 7��
			mmax = max(mmax, arr[y+1][x] + arr[y+1][x + 1] + arr[y + 2][x + 1]); // 8��
			mmax = max(mmax, arr[y][x + 1] + arr[y + 1][x] + arr[y+1][x-1]); // 9��
			mmax = max(mmax, arr[y][x-1] + arr[y+1][x-1] + arr[y-1][x]); // 10��
			mmax = max(mmax, arr[y][x + 1] + arr[y+1][x + 1] + arr[y + 1][x + 2]); // 11��
			mmax = max(mmax, arr[y][x+1] + arr[y][x + 2] + arr[y + 1][x + 1]); // 12��
			mmax = max(mmax, arr[y][x+1] + arr[y-1][x+1] + arr[y + 1][x + 1]); // 13��
			mmax = max(mmax, arr[y][x + 1] + arr[y][x + 2] + arr[y -1][x + 1]); // 14��
			mmax = max(mmax, arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x + 1]); // 15��
			mmax = max(mmax, arr[y][x+1] + arr[y][x + 2] + arr[y+1][x + 2]); // 16��
			mmax = max(mmax, arr[y + 1][x] + arr[y+1][x + 1] + arr[y + 1][x + 2]); // 17��
			mmax = max(mmax, arr[y + 1][x] + arr[y + 2][x] + arr[y][x + 1]); // 18��
			mmax = max(mmax, arr[y + 1][x] + arr[y+2][x] + arr[y + 2][x-1]); // 19��

			fmax = max(fmax, mmax + arr[y][x]);
		}
	}
	cout << fmax << "\n";
	return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;

int arr[505][505];

int main() {

	int N, M;
	int fmax = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int y = 0; y < N; y++) { // y�� y��
		for (int x = 0; x < M; x++) { // x�� x��
			if (y + 3 < N)
				fmax = max(fmax, arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 3][x]);
			if (x + 3 < M)
				fmax = max(fmax, arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y][x + 3]);
			if (y + 1 < N && x + 1 < M)
				fmax = max(fmax, arr[y][x] + arr[y][x + 1] + arr[y + 1][x] + arr[y + 1][x + 1]);
			if (y + 1 < N && x + 2 < M) {
				fmax = max(fmax, arr[y][x] + arr[y][x + 1] + arr[y][x+2] + arr[y + 1][x]); // 5��
				fmax = max(fmax, arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 1][x + 2] + arr[y][x + 2]); // 7��
				fmax = max(fmax, arr[y + 1][x] + arr[y + 1][x + 1] + arr[y][x+1] + arr[y][x + 2]); // 9��
				fmax = max(fmax, arr[y][x] + arr[y][x + 1] + arr[y + 1][x+1] + arr[y + 1][x + 2]); // 11��
				fmax = max(fmax, arr[y][x] + arr[y][x + 1] + arr[y + 1][x+1] + arr[y][x + 2]); // 12��
				fmax = max(fmax, arr[y+1][x] + arr[y+1][x + 1] + arr[y][x+1] + arr[y + 1][x + 2]); // 14��
				fmax = max(fmax, arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 2]); // 16��
				fmax = max(fmax, arr[y][x] + arr[y + 1][x] + arr[y+1][x + 1] + arr[y + 1][x + 2]); // 17��

			}
			if (y + 2 < N && x + 1 < M) {
				fmax = max(fmax, arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 2][x + 1]); // 4��
				fmax = max(fmax, arr[y][x] + arr[y][x + 1] + arr[y + 1][x+1] + arr[y + 2][x + 1]); // 6��
				fmax = max(fmax, arr[y][x] + arr[y+1][x + 1] + arr[y + 1][x] + arr[y + 2][x + 1]); // 8��
				fmax = max(fmax, arr[y+1][x] + arr[y+2][x] + arr[y + 1][x+1] + arr[y][x + 1]); // 10��
				fmax = max(fmax, arr[y+1][x] + arr[y+1][x + 1] + arr[y][x+1] + arr[y + 2][x + 1]); // 13��
				fmax = max(fmax, arr[y][x] + arr[y+1][x] + arr[y + 2][x] + arr[y + 1][x + 1]); // 15��
				fmax = max(fmax, arr[y][x] + arr[y + 1][x] + arr[y][x + 1] + arr[y + 2][x]); // 18��
				fmax = max(fmax, arr[y+2][x] + arr[y + 2][x + 1] + arr[y+1][x + 1] + arr[y][x + 1]); // 19��
			}
		}
	}
	cout << fmax << "\n";
	return 0;
}
*/
