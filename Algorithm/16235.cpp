#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

// 2024.05.03
// Writen by JongTKim

// 푼 방법 : 구현, 자료구조, 시뮬레이션 

struct namu {int y, x, age;};
int N, M, K;
int x, y, z;
int arr[12][12]; // 남은 양분 배열, 초기값은 5
int A[12][12]; // 양분 추가 배열
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
// priority_queue<namu, vector<namu>, comp> q; // 나무가 있는곳의 위치 -> PQ로 해도된다 이문제★
deque<namu> q;
queue<namu> q2, dtree; // q2 => 임시큐, dtree => 죽은 나무 체크큐




void spring() { // 봄 -> 나무 성장시즌
	int fsize = q.size();
	for (int i = 0; i < fsize; i++) {
		namu na = q.front();
		int y = na.y; int x = na.x; int age = na.age;
		q.pop_front();
		if (age <= arr[y][x]) {
			arr[y][x] -= age;
			q.push_back({ y,x,age + 1 });
		}
		else {
			dtree.push({ y,x,age });
			M--;
		}
	}
}

void summer() { // 여름 -> 죽은나무 양분화
	while(!dtree.empty()) {
		namu d = dtree.front();
		arr[d.y][d.x] += d.age / 2;
		dtree.pop();
	}
}

void fall() { // 가을 -> 나무 번식시즌
	int size = q.size();	
	for (int i = 0; i < size; i++) {
		namu na = q[i];

		if (na.age % 5 == 0) { // 나무 나이가 5의 배수면
			for (int i = 0; i < 8; i++) {
				int ny = na.y + dy[i];
				int nx = na.x + dx[i];
				if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
				// 번식할수있는 공간이면
				q2.push({ ny,nx,1 });
				M++;
			}
		}
	}
	
	// q와 q2로 나눠야 하는 이유는 바로 q.push_front()를 해줄경우 for(namu na : q)에 영향을 미치기 때문이다
	while (!q2.empty()) {
		q.push_front(q2.front());
		q2.pop();
	}
}

void winter() { // 겨울 -> 양분 채워주기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] += A[i][j];
		}
	}
}

void solve() {
	while (K) { // 년수가 남아있다면
		spring();
		summer();
		fall();
		winter();
		K--;
	}
}

void input() {
	cin >> N >> M >> K; // N은 맵크기, M은 초기 나무의 개수, K는 몇년후에 끝낼껀지
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> x >> y >> z;
		q.push_back({ x,y,z });
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(&arr[0][0], &arr[11][12], 5); // 양분 배열을 5로 초기화
	input();
	solve();
	cout << M << "\n";
	return 0;
}