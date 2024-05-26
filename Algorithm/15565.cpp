#include<bits/stdc++.h>
using namespace std;

// 2024.05.26
// Written by JongTKim

// 푼 방법 : 투포인터, 큐

int N, K;
int mmin = 1<<20;
int cnt, arr[1000001];

/* 투포인터 풀이 */
void solve1() {
	for (int i = 0; i < N; i++) cin >> arr[i];
	int start = 0, end = 0; // 투포인터 잡아주고
	while (end <= N) {
		if (cnt < K) { // 아직 K개의 라이언을 못뽑았을때는 end를 계속 늘려줘야함
			if (arr[end] == 1) cnt++;
			end++;
		}
		else if (cnt == K) { // K개의 라이언을 찾았다면 이제 최적화를 시작해야함
			mmin = min(mmin, end - start);
			while (cnt > K - 2) {
				if (arr[start] == 1) cnt--;
				start++;
			}
			start--;
			cnt++;
		}
	}
}

/* 큐를 이용한 슬라이딩 윈도우 */
void solve2() {
	queue<int> q;
	char num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == '1') {
			q.push(i);
			if (q.size() == K) {
				mmin = min(mmin, q.back() - q.front() + 1);
				q.pop();
			}
		}
	}
}
void input() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
}
int main() {
	input();
	//solve1();
	solve2();
	if (mmin == 1<<20) cout << -1 << "\n";
	else cout << mmin << "\n";
	return 0;
}