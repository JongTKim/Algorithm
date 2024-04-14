#include<bits/stdc++.h>
using namespace std;

// 2024.04.14
// Writen by JongTKim

// 푼 방법 : BFS + 우선순위 큐

int N, K, S, Y, X;
int arr[202][202];
vector<pair<int, int>> vec;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

struct test {
	int t;
	int knum;
	int y;
	int x;
	test(int T, int Knum, int Y, int X) : t(T), knum(Knum), y(Y), x(X) {}
};

struct comp {
	bool operator()(test A, test B)
	{
		if (A.t > B.t)
			return true;
		else if (A.t == B.t)
			return A.knum > B.knum;
		return false;
	}
};


void bfs() {

	priority_queue<test, vector<test>, comp> q;
	// pq로 하면 안되는이유 : 시간이 무시됨!

	for (pair<int, int> pr : vec) {
		int y = pr.first;
		int x = pr.second;
		q.push(test(0, arr[y][x], y, x));
	}

	while (!q.empty()) {
		int y = q.top().y;
		int x = q.top().x;
		int t = q.top().t;

		q.pop();

		if (t == S) break;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 1 || ny > N || nx < 1 || nx > N) continue; // overflow

			if (arr[ny][nx] != 0) continue; // 이미있는곳은 못감

			arr[ny][nx] = arr[y][x];
			q.push(test(t + 1, arr[ny][nx], ny, nx));
		}
	}
}
int main() {

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) vec.push_back({ i,j });
		}
	}
	cin >> S >> Y >> X;

	bfs();

	cout << arr[Y][X] << "\n";
	return 0;
}