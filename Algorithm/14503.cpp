#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

// 2024.05.02
// Writen by JongTKim

// 푼 방법 : 구현, 시뮬레이션

int N, M;
int r,c,d;
int arr[51][51];
int visited[51][51];
int nnum;
// 북 동 남 서
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void dfs(int sy, int sx) {
	int y = 0; 
	int x = 0;
	visited[sy][sx] = 1;

	for(int i=0; i<4; i++){
		int loc = (d + 3 - i) % 4; // 이 공식을 찾는게 어렵다
		y = sy + dy[loc];
		x = sx + dx[loc];

		if (arr[y][x] || visited[y][x]) continue; // 갈수없는곳 체크

		// 여기까지 왔으면 갈수있는곳이 있다
		nnum++; d = loc;
		dfs(y, x);
	}
	// 여기까지 온거면 4칸다 빈칸이없는경우 후진하자
	y = sy - dy[d];
	x = sx - dx[d];

	if (arr[y][x]) {
		cout << nnum+1 << "\n";
		exit(0);
	}
	dfs(y, x);
}

void input() {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	input();
	dfs(r, c);
	return 0;
}