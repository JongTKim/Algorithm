#include<bits/stdc++.h>
using namespace std;

int N, M;
int arr[1001];
int sum;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N, greater<>()); // 오름차순 정렬

	int cnt = N;
	for (int i = 0; i < M; i++) {
		if (arr[i] <= 0) break;
		if (cnt <= 0) break;
		else { sum += arr[i], cnt -= 2; }
	}


	/*
	int len = N - (upper_bound(arr, arr + N, 0) - arr); // 0보다 큰 값이 몇개있는가?

	if (M >= len) { // 턴이 더 많거나 같을때에는 0보다 큰값들 다 가져갈수있음
		int num = N % 2 ? (N / 2) + 1 : N / 2;
		if (len > num) { // 다만, 상대도 가져가야하니깐
			for (int i = 0; i < num; i++) sum += arr[N - 1 - i];
		}
		else {
			for (int i = 0; i < len; i++) sum += arr[N - 1 - i];
		}
	}
	else { // 만약 턴이 더 적으면? => 턴만큼만 가져오면됨
		for (int i = 0; i < M; i++) sum += arr[N-1-i];
	}
	*/
	cout << sum << "\n";
	return 0;
}