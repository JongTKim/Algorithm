#include<bits/stdc++.h>
using namespace std;

// 2024.05.02
// Writen by JongTKim

// 푼 방법 : 그리디, 정렬
// ★중요★

int T, N;
int arr[10001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		int mmax = 0;

		cin >> N;

		for (int i = 0; i < N; i++) cin >> arr[i];

		sort(arr, arr + N);

		for (int i = 0; i < N-2; i++) mmax = max(mmax, arr[i + 2] - arr[i]);

		cout << mmax << "\n";
	}
	return 0;
}