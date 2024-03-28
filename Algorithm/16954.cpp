#include<bits/stdc++.h>
using namespace std;

char arr[8][8];
bool visited[20][8][8];
int dy[3] = { -1,0,1 };
int dx[3] = { -1,0,1 };

struct pos {
	int time, y, x;
};

int bfs() {
	queue<pos> q;

	q.push({ 0,7,0 }); // time:0, y:7, x:0 ���� ����
	visited[0][7][0] = true;

	while (!q.empty()) {
		int t = q.front().time;
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		if (y == 0) return 1; // ������ �ö󰡸� ����

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) { // ���� �������� 9�������� ������
				int ny = y + dy[i];
				int nx = x + dx[j];
				int nt = t + 1;

				// 0. 8�ʵ��� ����ٸ� ����
				/*if (nt > 8)
					return 1;*/

					// 1. ������ ����� �ʴ°�
				if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8)
					continue;

				// 2. ������ �ڸ��� ���� ���������ʴ°�
				if (arr[ny - t][nx] == '#')
					continue;

				// 3. ����� ���̾����� 1���Ŀ� ���� �������°�
				if (arr[ny - nt][nx] == '#')
					continue;

				if (visited[nt][ny][nx]) {
					continue;
				}

				visited[nt][ny][nx] = true;

				q.push({ nt, ny, nx });

			}
		}
	}

	return 0;
}
int main() {

	string str;

	for (int i = 0; i < 8; i++) {
		cin >> str;
		for (int j = 0; j < 8; j++) {
			arr[i][j] = str[j];
		}
	}
	// �Է¹ޱ� �Ϸ�

	cout << bfs() << "\n";
	return 0;
}