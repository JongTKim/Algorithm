#include<bits/stdc++.h>
using namespace std;

// 2024.04.26
// Writen by JongTKim

// 푼 방법 : BFS
// ★중요★

int N, M;
string str;
int arr[1010][1010];
int visited[1010][1010][2];
int dy[4] = { -1,0,1,0 }; int dx[4] = { 0,1,0,-1 };
struct st { int y, x, flag; };

int bfs(int y, int x) {

	queue<st> q;
	q.push(st{ y, x, 0 });
	visited[y][x][0] = 1;

	while (!q.empty()) {
		st s = q.front();
		q.pop();

		if (s.y == N && s.x == M) return visited[s.y][s.x][s.flag]; // 처음 도착했을때가 최소거리임

		for (int i = 0; i < 4; i++) {
			int ny = s.y + dy[i];
			int nx = s.x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue; // 범위를 벗어나는지 확인
			if (!arr[ny][nx] && visited[ny][nx][s.flag] == 0) { // 다음 갈곳에 벽이없고 아직 방문하지 않았다면
				visited[ny][nx][s.flag] = visited[s.y][s.x][s.flag] + 1;
				q.push(st{ ny, nx, s.flag });
			}
			if (arr[ny][nx] == 1 && s.flag == 0){ // 다음 갈곳에 벽이있지만 아직 깬벽이 없어서 갈수있는경우
				// 왜 visited[ny][nx][1] == 0인 경우는 확인하지 않아도 될까?(있어도 상관은 X)
				// => 벽은 하나까지만 깰수있고 다른곳에서 깬벽이 거리가 더 낮게 이쪽으로 오더라도 s.flag==0 조건에서 걸리기 때문에 안된다.
				visited[ny][nx][1] = visited[s.y][s.x][s.flag] + 1;
				q.push(st{ ny, nx, 1 });
			}
		}
	}

	return -1;
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= M; j++) arr[i][j] = (str[j - 1] - '0');
	}
	cout << bfs(1, 1) << "\n";
}
