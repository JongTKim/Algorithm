#include<bits/stdc++.h>
using namespace std;

// 2024.06.02
// Written by JongTKim

// 푼 방법 : 구현

int N, M, maxn;
int prevv, pos; // 이전수와 현재수를 담는다

void input() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
}

int main() {
	input();
	cin >> N >> M >> prevv;
	maxn = prevv; // 처음에는 가로등 하나밖에 겹치지 못한다.
	for (int i = 0; i < M-1; i++) {
		cin >> pos;
		maxn = max(maxn, (pos - prevv + 1) / 2); // 중간에는 가로등 두개가 겹칠수 있다.
		prevv = pos;
	}
	maxn = max(maxn, N - prevv); // 마지막에는 가로등 하나밖에 겹치지 못한다
	cout << maxn << "\n";
	return 0;
}