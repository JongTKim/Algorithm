#include<bits/stdc++.h>
using namespace std;

typedef struct point {
	int height;
	pair<int, int> coor;

	point(int h, pair<int, int> c) {
		height = h;
		coor = c;
	}
} Point;

struct comp {
	bool operator()(Point a, Point b){
		return a.height < b.height;
	}
};

int M, N;
int arr[501][501];
int dp[501][501];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int bfs(int y, int x) {

	priority_queue<Point, vector<Point>, comp> pq; // 정렬조건 중요함!!! 높이가 오르차순

	pq.push(Point(arr[y][x], { y,x }));

	dp[0][0] = 1;

	while (!pq.empty()) {
		pair<int, int> location = pq.top().coor;
		pq.pop();

		if (location == make_pair(M-1, N-1)) continue;

		for (int i = 0; i < 4; i++) {
			int ny = location.first + dy[i];
			int nx = location.second + dx[i];
			
			if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue; // overflow	

			if (arr[ny][nx] < arr[location.first][location.second]) { // 다음껀 높이가 더 낮아야함
				if (!dp[ny][nx]) { // 그리고 가지않은 곳이여야함
					pq.push(Point(arr[ny][nx], { ny, nx }));
				}
				dp[ny][nx] += dp[location.first][location.second];
			}
		}
	}
	return dp[M - 1][N - 1];
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	cout << bfs(0, 0) << "\n";
	return 0;
}