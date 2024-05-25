#include<bits/stdc++.h>
using namespace std;

// 2024.04.15
// Writen by JongTKim

// Ǭ ��� : BFS

struct virus {
	int knum;
	int y;
	int x;
	virus(int Knum, int Y, int X) : knum(Knum), y(Y), x(X) {}
};

int N, K, S, Y, X;
int arr[202][202];
vector<virus> vec;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

bool cmp(const virus& A, const virus& B) {
	return A.knum < B.knum;
}
	
void bfs() {

	queue<pair<int,virus>> q;
	// pq�� �ϸ� �ȵǴ����� : �ð��� ���õ�!

	for (virus v : vec) {
		q.push({ 0, { v.knum, v.y, v.x } });
	}

	while (!q.empty()) {
		int y = q.front().second.y;
		int x = q.front().second.x;
		int t = q.front().first;

		q.pop();

		if (t == S) break;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 1 || ny > N || nx < 1 || nx > N) continue; // overflow

			if (arr[ny][nx] != 0) continue; // �̹��ִ°��� ����

			arr[ny][nx] = arr[y][x];
			q.push({1,{arr[ny][nx],ny,nx}});
		}
	}
}
int main() {

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) vec.push_back({ arr[i][j], i,j });
		}
	}
	cin >> S >> Y >> X;
	sort(vec.begin(), vec.end(), cmp);;
	bfs();

	cout << arr[Y][X] << "\n";
	return 0;
}