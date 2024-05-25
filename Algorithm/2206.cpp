#include<bits/stdc++.h>
using namespace std;

// 2024.04.26
// Writen by JongTKim

// Ǭ ��� : BFS
// ���߿��

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

		if (s.y == N && s.x == M) return visited[s.y][s.x][s.flag]; // ó�� ������������ �ּҰŸ���

		for (int i = 0; i < 4; i++) {
			int ny = s.y + dy[i];
			int nx = s.x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue; // ������ ������� Ȯ��
			if (!arr[ny][nx] && visited[ny][nx][s.flag] == 0) { // ���� ������ ���̾��� ���� �湮���� �ʾҴٸ�
				visited[ny][nx][s.flag] = visited[s.y][s.x][s.flag] + 1;
				q.push(st{ ny, nx, s.flag });
			}
			if (arr[ny][nx] == 1 && s.flag == 0){ // ���� ������ ���������� ���� ������ ��� �����ִ°��
				// �� visited[ny][nx][1] == 0�� ���� Ȯ������ �ʾƵ� �ɱ�?(�־ ����� X)
				// => ���� �ϳ������� �����ְ� �ٸ������� ������ �Ÿ��� �� ���� �������� ������ s.flag==0 ���ǿ��� �ɸ��� ������ �ȵȴ�.
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
