#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

// 2024.05.01
// Writen by JongTKim

// 푼 방법 : BFS, 구현
// ★★중요★★

int N, M, nnum, ttime; // nnum은 현재 남아있는 빙하의 개수
int arr[301][301]; // 원래맵
int arr2[301][301]; // 복사맵 -> 원래맵의 갱신이 즉시 영향을 끼쳐서는 안되므로 복사맵이 필요하다
bool visited[301][301];
pr d[4] = { {-1,0},{0,1},{1,0},{0,-1} }; // 상우하좌 좌표이동

bool bfs(int y, int x) {

	int nnum2 = 1; // 이번에 방문한 빙하의 개수
	int nnum3 = 0; // 이번년에 녹아서 없어진곳의 개수

	queue<pr> q;

	visited[y][x] = 1;

	q.push({ y,x });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++) {

			int ny = y + d[i].first;
			int nx = x + d[i].second;

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue; // overflow check

			if (!arr[ny][nx]) { // 다음 가려는곳이 물이면 높이가 1씩 줄어든다
				if (!arr2[y][x]) continue;
				arr2[y][x]--;
				if (!arr2[y][x]) nnum3++; // ★이거 이해가 중요하다★
				continue;
			}

			else if (!visited[ny][nx]) { // 여기까지 오면 다음 가려는곳이 빙하다. 방문여부 확인
				visited[ny][nx] = 1;
				nnum2++;
				q.push({ ny,nx });
			}
		}
	}
	// 여기까지 오면 처음 탐색 시작한점과 연결된 모든점을 탐색한거다
	if (nnum2 == nnum) {
		nnum -= nnum3;
		return true;
	}

	// 근데 남은 빙하의 수와 탐색한 빙하의 수가 다르다면 분리된 어떤점은 탐색 안됐다는거겠지?
	else return false;  

}

void input() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) nnum++;
		}
	}
}
int main() {

	input();
	
	while (true) {

		memset(visited, false, sizeof(visited));

		pr loc; int flag = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!flag && arr[i][j]) flag=1, loc = { i,j }; // 전체 map에서 처음 빙하지점 찾기
				arr2[i][j] = arr[i][j];
			}
		}

		if (!bfs(loc.first, loc.second)) {
			cout << ttime << "\n";
			return 0;
		}

		if (nnum == 0) { // 한번에 다 없어진경우
			cout << 0 << "\n";
			return 0;
		}
		
		ttime++;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = arr2[i][j];
			}
		}
	}

	return 0;
}