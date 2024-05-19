#include<bits/stdc++.h>
using namespace std;

// 2024.05.19
// Written by JongTKim

// 푼 방법 : 이분탐색

int N, M, num; // 칭호의 개수, 출력해야하는 캐릭터의 개수, 각 전투력
int power[100001];
string title[100001];

// 이분탐색 로직. 탐색할때마다 N으로 선형 검색하던걸 longN으로 줄일수있음
// 따라서 O(NM)이였던 시간 복잡도를 O(MlongN)으로 줄일수있다.
void solve2() {
	cin >> num;
	// 이분탐색을 직접 구현하지않고 lower_bound를 사용하여 해결.
	int idx = lower_bound(power, power + N, num) - power;
	cout << title[idx] << "\n";
}

void solve1() {
	cin >> num;
	int mid = 0, left = 0, right = N - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (num <= power[mid]) right = mid - 1; // 같은 경우도 더 내려서 먼저 들어온 칭호가 있는지 확인
		else left = mid + 1;
	}
	if (num > power[mid]) cout << title[mid + 1] << "\n";
	else cout << title[mid] << "\n";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> title[i] >> power[i];
	for (int i = 0; i < M; i++) solve1();
	return 0;
}