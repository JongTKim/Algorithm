#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

// 2024.05.03
// Writen by JongTKim

// Ǭ ��� : ����, �ڷᱸ��, �ùķ��̼� 

struct namu {int y, x, age;};
int N, M, K;
int x, y, z;
int arr[12][12]; // ���� ��� �迭, �ʱⰪ�� 5
int A[12][12]; // ��� �߰� �迭
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
// priority_queue<namu, vector<namu>, comp> q; // ������ �ִ°��� ��ġ -> PQ�� �ص��ȴ� �̹�����
deque<namu> q;
queue<namu> q2, dtree; // q2 => �ӽ�ť, dtree => ���� ���� üũť




void spring() { // �� -> ���� �������
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

void summer() { // ���� -> �������� ���ȭ
	while(!dtree.empty()) {
		namu d = dtree.front();
		arr[d.y][d.x] += d.age / 2;
		dtree.pop();
	}
}

void fall() { // ���� -> ���� ���Ľ���
	int size = q.size();	
	for (int i = 0; i < size; i++) {
		namu na = q[i];

		if (na.age % 5 == 0) { // ���� ���̰� 5�� �����
			for (int i = 0; i < 8; i++) {
				int ny = na.y + dy[i];
				int nx = na.x + dx[i];
				if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
				// �����Ҽ��ִ� �����̸�
				q2.push({ ny,nx,1 });
				M++;
			}
		}
	}
	
	// q�� q2�� ������ �ϴ� ������ �ٷ� q.push_front()�� ���ٰ�� for(namu na : q)�� ������ ��ġ�� �����̴�
	while (!q2.empty()) {
		q.push_front(q2.front());
		q2.pop();
	}
}

void winter() { // �ܿ� -> ��� ä���ֱ�
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] += A[i][j];
		}
	}
}

void solve() {
	while (K) { // ����� �����ִٸ�
		spring();
		summer();
		fall();
		winter();
		K--;
	}
}

void input() {
	cin >> N >> M >> K; // N�� ��ũ��, M�� �ʱ� ������ ����, K�� ����Ŀ� ��������
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
	fill(&arr[0][0], &arr[11][12], 5); // ��� �迭�� 5�� �ʱ�ȭ
	input();
	solve();
	cout << M << "\n";
	return 0;
}