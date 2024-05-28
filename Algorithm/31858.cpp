#include<bits/stdc++.h>
using namespace std;

// 2024.05.28
// Written by JongTKim

// 푼 방법 : 브루트포스, 백트래킹

int N, K, num;
vector<int> vec, vec2;
int arr[8];
bool visited[8];
int mcnt;

void dfs(int day, int cur) {
	if (day == N - 1) {
		mcnt++; return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i] && cur - K + arr[i] >= 500) {
			visited[i] = true;
			dfs(day + 1, cur - K + arr[i]);
			visited[i] = false;
		}
	}
}
void solve2() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dfs(0, 500);
}
void solve1() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
		vec2.push_back(i);
	}

	do {
		int cnt = 0, flag = 0, son = K;
		for (int c : vec2) {
			cnt += vec[c];
			if (cnt < son) {
				flag = 1;
				break;
			}
			son += K;
		}
		if (!flag) mcnt++;
	} while (next_permutation(vec2.begin(), vec2.end())); // 순열구하기

}
int main() {
	solve2();
	cout << mcnt << "\n";
	return 0;
}