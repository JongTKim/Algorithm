#include<bits/stdc++.h>
using namespace std;
#define MAX 32001

// 2024.03.30
// Writen by JongTKim

int main() {

	// 푼방법
	// 위상정렬 + 우선순위 큐

	int N, M, A, B;
	int degree[MAX] = { 0 };

	vector<int> vec[MAX]; // 번호별로 풀어야 풀수있는 문제가 들어감 vec[4]={1,2,3} 이 있으면 4번문제는 1,2,3번 문제보다 먼저 풀어야함

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		vec[A].push_back(B);
		degree[B]++; // 2번 조건 완수를 위한 코드, degree가 존재하면 먼저 풀어야될 문제가 있다는 소리임
	}
	// 입력완료

	priority_queue<int, vector<int>, greater<int>> pq; // 3번 조건 완수를 위한 코드, 가능한게 여러개 있어도 쉬운 문제부터 풀어야되니깐 오름차순 정렬

	for (int i = 1; i <= N; i++) {
		if (!degree[i]) pq.push(i); // degree가 존재하는것은 지금 당장 풀 수 있는 문제다. 선행 문제가 없는 경우
	}

	while (!pq.empty()) {
		int solve = pq.top(); // 이번에 풀 문제번호
		pq.pop();

		cout << solve << " ";

		for (int i : vec[solve]) {
			degree[i]--; // 위상 하나씩 줄여주기
			if (degree[i] == 0) // 만약 줄어서 0이됐다면 이제 풀수있는 문제임 push 해줌
				pq.push(i);
		}
	}
	return 0;
}