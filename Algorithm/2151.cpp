#include<bits/stdc++.h>
using namespace std;

int N;
char ch[51][51];
vector<pair<int,int>> vec; // �� ���� ���� ��ǥ�� ����
string str;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int visited[51][51][4];

struct pos { int y, x, dir; };

bool overflow(int y, int x) { // ���� ��Ұ� �����ִ� �� ���� Ȯ�����ִ� �Լ� (���� ������ true)
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

	memset(visited, -1, sizeof(visited)); // -1�� �ʱ�ȭ�� �ؼ� �Ȱ����� -1, �������ε� �ſ��� �ϳ��� �� ��ġ�Ѱ� 0�� ����

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

		if (y == vec[1].first && x == vec[1].second) continue; // �������� �����ϸ� ���̻� �������� ����

		//���� ��ġ�Ѵٸ� ���� ���⿡ ���� �ι������� ��������(�ٸ�, ���� ��ġ�Ҽ��ִ� ��ġ�϶��� ����)

		if (ch[y][x] == '!') { // ���� ���� ��ġ�Ѵٸ�
			if (dir == 0 || dir == 2) { // ��,�Ʒ��� �Դٸ� ��,���� ��������
				for (int i = 1; i <= 3; i += 2) {
					int ny = y + dy[i]; int nx = x + dx[i];
					if (!overflow(ny, nx)) continue;
					if (visited[ny][nx][i] == -1 || visited[ny][nx][i] > visited[y][x][dir] + 1) {// �ƿ� �Ȱ������̰ų�, ������ ���� �� �ִ����� ����������
						q.push(pos{ ny, nx, i }); 
						visited[ny][nx][i] = visited[y][x][dir] + 1;
					}
				}
			}
			if (dir == 1 || dir == 3) { // ��,������ �Դٸ� ��,�Ʒ��� ��������
				for (int i = 0; i <= 2; i += 2) {
					int ny = y + dy[i]; int nx = x + dx[i];
					if (!overflow(ny, nx)) continue;
					if (visited[ny][nx][i] == -1 || visited[ny][nx][i] > visited[y][x][dir] + 1) {// �ƿ� �Ȱ������̰ų�, ������ ���� �� �ִ����� ����������
						q.push(pos{ ny, nx, i });
						visited[ny][nx][i] = visited[y][x][dir] + 1;
					}
				}
			}
		}

		// ��ġ���Ѵٸ� �׳� ������� �߰��ߵ�
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (!overflow(ny, nx)) continue;
		if (visited[ny][nx][dir] == -1 || visited[y][x][dir] + 1 < visited[ny][nx][dir]) { // ���� ������ �������̰ų�, 
			visited[ny][nx][dir] = visited[y][x][dir];
			q.push(pos{ ny, nx, dir });
		}
	}
	
	int mina = 99999; // 50x50 ���̴� ��� �ʿ� �ſ��� �ִ��ص� 2500�� �������¾���
	for (int i = 0; i < 4; i++) {
		if (visited[vec[1].first][vec[1].second][i] != -1) {
			mina = min(mina, visited[vec[1].first][vec[1].second][i]);
		}
	}
	cout << mina << "\n";
	return 0;
}