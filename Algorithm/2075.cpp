#include<bits/stdc++.h>
using namespace std;

// 2024.05.09
// Written by JongTKim

// 푼 방법 : 자료구조, 우선순위 큐

int N;
//int arr[2250001];

/*void solve1() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i * N + j];
	}
	sort(arr, arr + (N * N));
	cout << arr[(N * (N - 1))] << "\n";
}*/

void solve2() {
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	int temp;
	for (int i = 0; i < N*N; i++) {
		cin >> temp;
		pq.push(temp);
		if (pq.size() > N) pq.pop();
	}
	cout << pq.top() << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// solve1();
	solve2();

	return 0;
}