#include<bits/stdc++.h>
using namespace std;

// 2024.04.13
// Writen by JongTKim

// 푼 방법 : DFS

int N, M;
int num1, num2;
int visited[105];
vector<int> vec[105];
vector<int> vec2[105];
int cnt;

void dfs(int num) { // 자기보다 작은 관계 확점
	for (int c : vec[num]) if (!visited[c]) visited[c] = 1, cnt++, dfs(c);
}

void dfs2(int num) { // 자기보다 큰 관계 확점
	for (int c : vec2[num])if (!visited[c]) visited[c] = 1, cnt++, dfs2(c);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> num1 >> num2;
		vec[num1].push_back(num2);
		vec2[num2].push_back(num1);
	}

	for (int i = 1; i <= N; i++) {
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		dfs(i); // 자신보다 작은 관계를 확정짓는 dfs
		dfs2(i); // 자신보다 큰 관계를 확정짓는 dfs
		cout << N - cnt - 1 << "\n"; // -1을 해주는 이유는 자기자신 빼기
	}

	return 0;
}