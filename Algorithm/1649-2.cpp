#include<bits/stdc++.h>
using namespace std;

int city[205];
int arr[205][205];
int plan[1005]; // 여행 계획 배열
vector<int> vec;

int getparent(int x) {
	if (city[x] == x) return x;
	return getparent(city[x]);
}

void unionparent(int a, int b) {
	a = getparent(a);
	b = getparent(b);
	if (a < b) city[b] = a;
	else if (a == b) return;
	else city[a] = b;
}

int findparent(int a, int b) {
	a = getparent(a);
	b = getparent(b);
	if (a == b) return 1;
	return 0;
}

int main() {
	int N, M;
	
	// 도시 수, 계획 수 입력
	cin >> N >> M;
	vec.resize(N + 1, 0);

	// union-find 기본 (중요 : 연결정보와 같이 입력하면 안됨)
	for (int i = 1; i <= N; i++) {
		city[i] = i;
	}

	// 도시 연결정보 입력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) unionparent(i, j);
		}
	}

	// 계획 입력
	for (int i = 0; i < M; i++) cin >> plan[i];

	// 계획 가능한지 판단
	for (int i = 0; i < M - 1; i++) {
		if (findparent(plan[i], plan[i + 1])) // 두 개 도시의 부모가 같은지 확인한다.
			continue;
		else {
			cout << "NO" << "\n";
			exit(0);
		}
	}

	cout << "YES" << "\n";
	return 0;

}