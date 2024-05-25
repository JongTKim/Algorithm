#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;

int N, M, R, C;
int Y, X, wal;
int visited[1001][1001];
struct zip { int y, x, wal; };
vector<zip> zips;
vector<pr> mart;
queue<pr> q;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int mins = 100000000;
void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || ny > N || nx < 1 || nx > M) continue;
			if (visited[ny][nx] > visited[y][x] + 1) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
}


int main() {
	cin >> N >> M >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> Y >> X >> wal;
		zips.push_back({ Y,X, wal});
	}
	fill(&visited[0][0], &visited[1000][1001], 10000);
	for (int i = 0; i < C; i++) {
		cin >> Y >> X;
		q.push({ Y,X });
		visited[Y][X] = 0;
	}
	bfs();
	// 여길 끝내고 나오면 다되어있다

	for (zip p : zips) {
		mins = min(mins, visited[p.y][p.x] * p.wal);
	}
	cout << mins << "\n";
	return 0;
}