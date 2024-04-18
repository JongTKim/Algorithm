#include<bits/stdc++.h>
using namespace std;

int N;
char ch[51][51];
vector<pair<int,int>> vec; // 두 개의 문의 좌표가 들어갈곳
string str;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int visited[51][51][4];

struct pos { int y, x, dir; };

bool overflow(int y, int x) { // 다음 장소가 갈수있는 곳 인지 확인해주는 함수 (갈수 있을시 true)
	if (y < 0 || y >= N || x < 0 || x >= N || ch[y][x] == '*') return false;
	else return true;
}

int main() {
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> str;
		for (int j = 0; j < N; j++) {
			ch[i][j] = str[j];
			if (ch[i][j] == '#') vec.push_back({ i,j });
		}
	}

	memset(visited, -1, sizeof(visited)); // -1로 초기화를 해서 안가본곳 -1, 가본곳인데 거울을 하나도 안 설치한곳 0로 설정

	queue<pos> q;

	for (int i = 0; i < 4; i++) {
		int ny = vec[0].first + dy[i];
		int nx = vec[0].second + dx[i];
		if (ny < 0 || ny > N || nx < 0 || nx > N || ch[ny][nx] == '*') continue;
		else {
			q.push(pos{ ny,nx,i });
			visited[ny][nx][i] = 0;
		}
	}


	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;

		q.pop();

		if (y == vec[1].first && x == vec[1].second) continue; // 도착지에 도착하면 더이상 진행하지 않음

		//문을 설치한다면 빛의 방향에 따라 두방향으로 갈수있음(다만, 문을 설치할수있는 위치일때만 가능)

		if (ch[y][x] == '!') { // 만약 문을 설치한다면
			if (dir == 0 || dir == 2) { // 위,아래서 왔다면 왼,오로 갈수있음
				for (int i = 1; i <= 3; i += 2) {
					int ny = y + dy[i]; int nx = x + dx[i];
					if (!overflow(ny, nx)) continue;
					if (visited[ny][nx][i] == -1 || visited[ny][nx][i] > visited[y][x][dir] + 1) {// 아예 안가본곳이거나, 가려는 곳을 더 최단으로 갈수있을때
						q.push(pos{ ny, nx, i }); 
						visited[ny][nx][i] = visited[y][x][dir] + 1;
					}
				}
			}
			if (dir == 1 || dir == 3) { // 왼,오에서 왔다면 위,아래로 갈수있음
				for (int i = 0; i <= 2; i += 2) {
					int ny = y + dy[i]; int nx = x + dx[i];
					if (!overflow(ny, nx)) continue;
					if (visited[ny][nx][i] == -1 || visited[ny][nx][i] > visited[y][x][dir] + 1) {// 아예 안가본곳이거나, 가려는 곳을 더 최단으로 갈수있을때
						q.push(pos{ ny, nx, i });
						visited[ny][nx][i] = visited[y][x][dir] + 1;
					}
				}
			}
		}

		// 설치안한다면 그냥 가던길로 쭉가야됨
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (!overflow(ny, nx)) continue;
		if (visited[ny][nx][dir] == -1 || visited[y][x][dir] + 1 < visited[ny][nx][dir]) { // 만약 가보지 않은곳이거나, 
			visited[ny][nx][dir] = visited[y][x][dir];
			q.push(pos{ ny, nx, dir });
		}
	}
	
	int mina = 99999; // 50x50 맵이니 모든 맵에 거울이 있다해도 2500을 넘을수는없음
	for (int i = 0; i < 4; i++) {
		if (visited[vec[1].first][vec[1].second][i] != -1) {
			mina = min(mina, visited[vec[1].first][vec[1].second][i]);
		}
	}
	cout << mina << "\n";
	return 0;
}