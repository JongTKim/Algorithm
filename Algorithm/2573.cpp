#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

// 2024.05.01
// Writen by JongTKim

// Ǭ ��� : BFS, ����
// �ڡ��߿�ڡ�

int N, M, nnum, ttime; // nnum�� ���� �����ִ� ������ ����
int arr[301][301]; // ������
int arr2[301][301]; // ����� -> �������� ������ ��� ������ ���ļ��� �ȵǹǷ� ������� �ʿ��ϴ�
bool visited[301][301];
pr d[4] = { {-1,0},{0,1},{1,0},{0,-1} }; // ������� ��ǥ�̵�

bool bfs(int y, int x) {

	int nnum2 = 1; // �̹��� �湮�� ������ ����
	int nnum3 = 0; // �̹��⿡ ��Ƽ� ���������� ����

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

			if (!arr[ny][nx]) { // ���� �����°��� ���̸� ���̰� 1�� �پ���
				if (!arr2[y][x]) continue;
				arr2[y][x]--;
				if (!arr2[y][x]) nnum3++; // ���̰� ���ذ� �߿��ϴ١�
				continue;
			}

			else if (!visited[ny][nx]) { // ������� ���� ���� �����°��� ���ϴ�. �湮���� Ȯ��
				visited[ny][nx] = 1;
				nnum2++;
				q.push({ ny,nx });
			}
		}
	}
	// ������� ���� ó�� Ž�� ���������� ����� ������� Ž���ѰŴ�
	if (nnum2 == nnum) {
		nnum -= nnum3;
		return true;
	}

	// �ٵ� ���� ������ ���� Ž���� ������ ���� �ٸ��ٸ� �и��� ����� Ž�� �ȵƴٴ°Ű���?
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
				if (!flag && arr[i][j]) flag=1, loc = { i,j }; // ��ü map���� ó�� �������� ã��
				arr2[i][j] = arr[i][j];
			}
		}

		if (!bfs(loc.first, loc.second)) {
			cout << ttime << "\n";
			return 0;
		}

		if (nnum == 0) { // �ѹ��� �� ���������
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