#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// 2024.05.06
// Written by JongTKim

// 푼 방법 : 슬라이딩 윈도우, 누적 합

int psum[250005];
int N, X, nnum, cnt;
ll maxn;
vector<int> vec;

void input() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> N >> X;

	for (int i = 1; i <= N; i++) {
		cin >> nnum;
		psum[i] = psum[i - 1] + nnum;
	}
}
int main() {
	
	input();

	for (int i = X; i <= N; i++) {
		if (psum[i] - psum[i - X] >= maxn) {
			maxn = psum[i] - psum[i - X];
			vec.push_back(maxn);
		}
	}

	if (maxn == 0) {
		cout << "SAD" << "\n";
		return 0;
	}

	for (int n : vec) {
		if (n == maxn) cnt++;
	}
	cout << maxn << "\n" << cnt << "\n";
	return 0;
}