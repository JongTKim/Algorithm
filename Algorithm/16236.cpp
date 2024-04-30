#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

// 2024.04.30
// Writen by JongTKim

// 푼 방법 : BFS, 구현, 시뮬레이션
// ★★중요★★

int N;
int msize=2; // 물고기의 현재사이즈
int flag; // 물고기가 잡아먹은 개수
pr loc; // 상어의 현위치
int ttime; // 총 걸린 시간
int arr[21][21]; // Map
int dy[4] = { -1,0,1,0 }; 
int dx[4] = { 0,1,0,-1 }; 
// 상좌하우 인데!! 사실, PQ를 쓰면 상관없다. 정렬이 자주일어나서 속도가 느려질것같긴하다


struct fish {
	int y, x, dist;
};

struct cmp {
	bool operator()(fish a, fish b) {
		if (a.dist == b.dist) {
			if (a.y == b.y)
				return a.x > b.x;
			return a.y > b.y;
		}
		return a.dist > b.dist;
	}
};

bool bfs(int y, int x) {

	int visited[21][21];
	memset(visited, 0, sizeof(visited));

	visited[y][x] = 1;

	//queue<pr> q;

	priority_queue<fish, vector<fish>, cmp> q;

	q.push(fish{ y, x, 0});

	while (!q.empty()) {

		int y = q.top().y;
		int x = q.top().x;
		int dist = q.top().dist;

		if (arr[y][x] && arr[y][x] < msize) {
			ttime += dist;
			loc = { y,x };
			// cout << ny << " " << nx << " " << dist + 1 << "\n";
			arr[y][x] = 0;
			flag + 1 == msize ? msize++, flag = 0 : flag++; // 상어 크기 커질준비가 됐다면 업그레이드
			return true;
		}

		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N || arr[ny][nx] > msize) continue;

			// ★이게 안되는 이유를 꼭꼭꼭꼭 살펴보자★
			/*if (arr[ny][nx] && arr[ny][nx] < msize) {
				ttime += dist+1;
				loc = { ny,nx };
				cout << ny << " " << nx << " " << dist+1 << "\n";
				arr[ny][nx] = 0;
				flag + 1 == msize ? msize++, flag = 0 : flag++; // 상어 크기 커질준비가 됐다면 업그레이드
				return true;
			}*/

			// 만약 arr[ny][nx] = 0인 경우
			if (!visited[ny][nx]) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push(fish{ ny,nx, dist+1});
			}
		}
	}
	return false;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				loc = { i,j };
				arr[i][j] = 0;
			}
		}
	}

	while (true) {
		if (!bfs(loc.first, loc.second)) break;
	}

	cout << ttime << "\n";
	return 0;
}