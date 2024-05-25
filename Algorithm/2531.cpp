#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// 2024.05.21
// Written by JongTKim

// Ǭ ��� : �����̵� ������, �ؽ� ��

// ----- ���� �������� -----
int N, d, k, c, mmax;
int arr[30001];

// ----- solve1 �������� -----
map<int, int> mp; // ���� count�� �ʿ��ϱ⿡ set ���� map�� ���

// ----- solve2 �������� -----
int cnt;
int visited[3001];


void countkind() {
	int count = mp.size();
	if (mp.find(c) == mp.end()) count += 1; // ������ �ϳ��߰� ����
	mmax = max(mmax, count);
}
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void solve1() { // �����̵� ������ - HashMap ���
	for (int i = 0; i < k; i++) mp[arr[i]]++; // �ʹ� k�� ä���
	countkind();
	int start = 0, end = k; // ��������
	while (start < N) {
		if (end >= N) end = end % N;
		mp[arr[start]]--;
		if (!mp[arr[start]]) mp.erase(arr[start]);
		mp[arr[end]]++;
		countkind();
		start++, end++;
	}
}

void solve2() { // �����̵� ������ - �迭 ���
	for (int i = 0; i < k; i++) {
		if (!visited[arr[i]]) cnt++; // �ʹ� k�� ä���
		visited[arr[i]]++;
	}
	mmax = max(mmax, cnt);
	int start = 0, end = k; // ��������
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