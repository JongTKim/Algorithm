#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

// 2024.04.24
// Written by JongTKim

// 푼 방법 : 구현, 시뮬레이션, 정렬
// ★★★꼭 다시풀기★★★

int r, c, k;
int arr[101][101];
int idx[101] = { 0 }; // 개수 세기
int ga = 100;
int row = 3; // 최대 행 개수
int col = 3; // 최대 열 개수
int ncnt[101];
vector<pr> rvec[101]; // pr은 {수, 개수}로 들어간다


void vecclear() {
	for (int i = 0; i < 101; i++) {
		rvec[i].clear();
	}
}

void mapClear() {
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			arr[i][j] = 0;
		}
	}
}


void fR() {

	for (int i = 0; i < col; i++) { // 모든 열을 돌면서, 그 열의 최대개수와 {수, 개수} 배열을 만들어야함
		memset(idx, 0, sizeof(idx));
		for (int j = 0; j < row; j++) {
			idx[arr[i][j]]++;
		}

		for (int j = 1; j < 101; j++) {
			if (idx[j]) rvec[i].push_back({ idx[j], j });
		}
	}

	mapClear();

	for (int i = 0; i < col; i++) {
		sort(rvec[i].begin(), rvec[i].end());
	}

	for (int i = 0; i < col; i++) {
		int nrow = rvec[i].size() * 2;
		row = max(row, nrow);
		int index = 0;
		for (int j = 0; j < rvec[i].size(); j++) {
			arr[i][index++] = rvec[i][j].second;
			arr[i][index++] = rvec[i][j].first;
		}
	}
}

void fC() { // C연산

	for (int i = 0; i < row; i++) { // 모든 열을 돌면서, 그 열의 최대개수와 {수, 개수} 배열을 만들어야함
		memset(idx, 0, sizeof(idx));
		for (int j = 0; j < col; j++) {
			idx[arr[j][i]]++;
		}

		for (int j = 1; j < 101; j++) {
			if (idx[j]) rvec[i].push_back({ idx[j], j });
		}
	}

	mapClear();

	for (int i = 0; i < row; i++) {
		sort(rvec[i].begin(), rvec[i].end());
	}

	for (int i = 0; i < row; i++) {
		int ncol = rvec[i].size() * 2;
		col = max(col, ncol);
		int index = 0;
		for (int j = 0; j < rvec[i].size(); j++) {
			arr[index++][i] = rvec[i][j].second;
			arr[index++][i] = rvec[i][j].first;
		}
	}
}

void solve() {
	while (ga) {

		ga--;

		vecclear();

		if (col >= row) fR();
		else fC();

		if (arr[r-1][c-1] == k) {
			cout << 100 - ga << "\n";
			exit(0);
		}
	}
	cout << -1 << "\n";
	exit(0);
}

void input() {
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

}

int main() {
	input();
	if (arr[r - 1][c - 1] == k) {
		cout << 0 << "\n";
	}
	else {
		solve();
	}
	return 0;
}