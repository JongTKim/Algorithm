#include<bits/stdc++.h>
using namespace std;

// 2024.04.13
// Writen by JongTKim

// 푼 방법 : BFS
int S;
bool dp[1001][1001]; // visited를 체크하는 배열. 만약 만든 개수가 2개이고, 클립보드 2개일때는 dp[2][2]=true 처리
int mina;


typedef struct Info {
	int num; // 현재 몇 개를 만들었는지
	int clip; // 클립보드에 몇개 들어가있는지
	int t; // 현재 시간은 몇초인지
	Info(int Num, int Clip, int T) : num(Num), clip(Clip), t(T) {}
};

void bfs() {
	queue<Info> q;
	q.push(Info(1, 1, 1)); // 처음에 클립보드에 담는경우(1번)을 했다 가정하고 시작

	while (!q.empty()) {
		int num = q.front().num;
		int cnum = q.front().clip;
		int t = q.front().t;

		q.pop();

		if (num <= 0) continue; // 0이하면 올라올수 있는 방법이 X, 0인데 클립보드에 10개가 들어가있으면 어떡해요? -> 그러면 10으로 다시 갈수도있으나, 애초에 그렇게 될 일이 없음

		if (num < cnum) continue;

		if (num == S) { // 만약, 원하는 개수에 도착하면 그때의 시간을 담고 break, BFS니깐 더 시간이 적게 나올수가없음
			mina = t;
			break;
		}

		dp[num][cnum] = true;

		if (num <= 1000) { // ** 범위를 잘 생각해보는것이 중요함
			if (!dp[num][num]) q.push(Info(num, num, t + 1)); // 복사(1번)
			if (!dp[num - 1][cnum]) q.push(Info(num - 1, cnum, t + 1)); // 빼기(3번)
		}
		if (num + cnum <= 1000) {
			if (!dp[num + cnum][cnum]) q.push(Info(num + cnum, cnum, t + 1)); // 붙여넣기(2번)
		}
	}
}
int main() {

	cin >> S;

	bfs();

	cout << mina << "\n";

	return 0;
}