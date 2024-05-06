#include<bits/stdc++.h>
using namespace std;

// 2024.05.06
// Written by JongTKim

// 푼 방법 : 이분 탐색, 매개 변수 탐색

int N, M;
int arr[10001];


void input() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> M;
	sort(arr, arr + N);
}

void solve1() {
	int maxn = arr[N - 1];

	if (maxn > M / N)
	{
		int cnt = M / N;
		int i = 0;

		for (i = 0; i < N; i++) {

			if (i == N - 1) break; // 종료조건 끝에왔으면 

			if (arr[i] <= cnt) M -= arr[i]; // 상한액보다 밑이므로 요청한 금액 그대로 배정할수있음

			else { // 만약 큰게 나왔으면 cnt 계산 다시돌려야함
				cnt = M / (N - i);
				if (arr[i] > cnt) break;
				else i--;
			}
		}
		if (maxn > M / (N - i)) cout << M / (N - i) << "\n";
		else cout << maxn << "\n";
	}
	else
		cout << maxn << "\n";
}

void solve2() {
	int start = 0;
	int end = arr[N - 1];
	int result, sum;

	while (start <= end) {
		sum = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < N; i++) {
			sum += min(arr[i], mid);
			if (sum > M) break; // 시간 단축
		}
		if (M >= sum) result = mid, start = mid + 1;
		else end = mid - 1;
	}
	cout << result;
}
int main() {
	input(); // 입력
	//solve1(); // 매개 변수 탐색
	solve2(); // 이분 탐색
	return 0;
}