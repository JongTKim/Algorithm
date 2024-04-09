#include<bits/stdc++.h>
using namespace std;

// 2024.04.09
// Writen by JongTKim

// 푼 방법 : 위상정렬

int arr[32005]; // 위상을 나타냄
vector<int> vec[32005];

int main() {
	
	int N, M;
	int a, b;

	cin >> N >> M;


	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		vec[a].push_back(b); // 위상 줄여주기 위해
		arr[b]++;
	}


	queue<int> q;

	for (int i = 1; i <= N; i++) { // 바로 세울수 있는애들
		if (!arr[i]) q.push(i);
	}

	while (!q.empty()) {

		int front = q.front();
		q.pop();
		for (int i : vec[front]) {
			arr[i]--;
			if (!arr[i]) q.push(i);
		}
		
		cout << front << " ";
	}


	return 0;
}