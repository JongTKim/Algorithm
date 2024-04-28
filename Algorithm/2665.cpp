#include<bits/stdc++.h>
using namespace std;

int N;
int arr[51][51];
int visited[51][51];
string str;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

struct ba {
	int y;
	int x;
	int num; //  검은 방을 흰방으로 바꾼 개수
};

struct comp {
	bool operator()(ba a, ba b) {
		return a.num > b.num; // num 오름차순으로 정렬
	}
};

int bfs() {

	priority_queue<ba, vector<ba>, comp> pq;

	pq.push({ 0, 0, 0 });
	visited[0][0] = 1;

	while (!pq.empty()) {
		int y = pq.top().y;
		int x = pq.top().x;
		int num = pq.top().num;

		pq.pop();

		if (y == N - 1 && x == N - 1) return num;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue; // overflow
			if (arr[ny][nx] == 0) { // 만약 다음 갈곳이 검은방이라면
				pq.push({ ny,nx,num + 1 });
				visited[ny][nx] = 1;
			}
			else { // 만약 다음 갈곳이 흰방이라면
				pq.push({ ny, nx, num });
				visited[ny][nx] = 1;
			}
		}
	}
}
int main() {
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> str;
		for (int j = 0; j < N; j++) arr[i][j] = (str[j]-'0');
	}

	cout << bfs() << "\n";
	return 0;
}