#include<bits/stdc++.h>
using namespace std;

// 2024.04.13
// Writen by JongTKim

// Ǭ ��� : DFS

int N, M;
int num1, num2;
int visited[105];
vector<int> vec[105];
vector<int> vec2[105];
int cnt;

void dfs(int num) { // �ڱ⺸�� ���� ���� Ȯ��
	for (int c : vec[num]) if (!visited[c]) visited[c] = 1, cnt++, dfs(c);
}

void dfs2(int num) { // �ڱ⺸�� ū ���� Ȯ��
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
		dfs(i); // �ڽź��� ���� ���踦 Ȯ������ dfs
		dfs2(i); // �ڽź��� ū ���踦 Ȯ������ dfs
		cout << N - cnt - 1 << "\n"; // -1�� ���ִ� ������ �ڱ��ڽ� ����
	}

	return 0;
}