#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// 2024.05.21
// Written by JongTKim

// 푼 방법 : 슬라이딩 윈도우, 해시 맵

// ----- 공통 전역변수 -----
int N, d, k, c, mmax;
int arr[30001];

// ----- solve1 전역변수 -----
map<int, int> mp; // 개수 count가 필요하기에 set 말고 map을 사용

// ----- solve2 전역변수 -----
int cnt;
int visited[3001];


void countkind() {
	int count = mp.size();
	if (mp.find(c) == mp.end()) count += 1; // 없으면 하나추가 가능
	mmax = max(mmax, count);
}
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void solve1() { // 슬라이딩 윈도우 - HashMap 사용
	for (int i = 0; i < k; i++) mp[arr[i]]++; // 초반 k개 채우기
	countkind();
	int start = 0, end = k; // 시작조건
	while (start < N) {
		if (end >= N) end = end % N;
		mp[arr[start]]--;
		if (!mp[arr[start]]) mp.erase(arr[start]);
		mp[arr[end]]++;
		countkind();
		start++, end++;
	}
}

void solve2() { // 슬라이딩 윈도우 - 배열 사용
	for (int i = 0; i < k; i++) {
		if (!visited[arr[i]]) cnt++; // 초반 k개 채우기
		visited[arr[i]]++;
	}
	mmax = max(mmax, cnt);
	int start = 0, end = k; // 시작조건
	while (start < N) {
		if (end >= N) end = end % N;
		visited[arr[start]]--;
		if (visited[arr[start]] == 0) cnt--;
		if (!visited[arr[end]]) cnt++;
		visited[arr[end]]++;
		if (visited[c]) mmax = max(mmax, cnt);
		else mmax = max(mmax, cnt + 1);
		start++, end++;
	}
}

int main() {
	input();
	solve1();
	cout << mmax << "\n";
	return 0;
}