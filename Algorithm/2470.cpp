#include<bits/stdc++.h>
using namespace std;

// 2024.05.11
// Written by JongTKim

// 푼 방법 : 투포인터, 이분탐색

int N;
int arr[100001];

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void solve1() {
	if (arr[0] > 0) { // 모두가 양수
		cout << arr[0] << " " << arr[1] << "\n"; // 오름차순 출력
	}
	else if (arr[N - 1] < 0) { // 모두가 음수
		cout << arr[N - 2] << " " << arr[N - 1] << "\n"; // 오름차순 출력
	}
	else { // 양수 음수 섞여있는 부분
		int left = 0, right = 0;
		for (left = 0; left < N - 1; left++) {
			if (arr[left] < 0 && arr[left + 1] > 0) break;
		}
		right = left + 1;
		int mmax = abs(arr[right] + arr[left]);
		int mright = right, mleft = left;

		if (left > 0) { // -2 -1 10 의 경우
			if (abs(arr[left] + arr[left - 1]) < mmax) {
				mmax = abs(arr[left] + arr[left - 1]);
				mleft = left - 1, mright = left;
			}
		}

		if (right < N - 1) { // -10 1 2 의 경우
			if (abs(arr[right] + arr[right + 1]) < mmax) {
				mmax = abs(arr[right] + arr[right + 1]);
				mleft = right, mright = right + 1;
			}
		}

		while (left >= 0 && right < N) {
			if (arr[right] + arr[left] > 0) {
				if (abs(arr[right] + arr[left]) < mmax) {
					mmax = abs(arr[right] + arr[left]);
					mleft = left, mright = right;
				}
				left--;
			}
			else if (arr[right] + arr[left] == 0) {
				mleft = left, mright = right;
				break;
			}
			else {
				if (abs(arr[right] + arr[left]) < mmax) {
					mmax = abs(arr[right] + arr[left]);
					mleft = left, mright = right;
				}
				right++;
			}
		}
		cout << arr[mleft] << " " << arr[mright] << "\n";
	}
}

void solve2() {
	int left = 0, right = N - 1, min = 2000000000;
	int mleft = 0, mright = 0;

	while (left < right) {
		int sum = arr[left] + arr[right];

		if (sum == 0) {
			mleft = left, mright = right;
			break;
		}
		if (min > abs(sum)) { // 갱신되는경우
			min = abs(sum);
			mleft = left, mright = right;
		}
		if (sum < 0) left++;
		else right--;
	}
	cout << arr[mleft] << " " << arr[mright] << "\n";
}

void solve3() {
	int left, right, mina = 2000000000;

	for (int i = 0; i <= N - 1; i++) {
		int loc = lower_bound(arr, arr + N, -arr[i]) - arr; // 파라미터의 값보다 같거나 큰 처음위치 반환

		if (loc > N - 1) loc = N-1; // 더 큰게없어서 마지막보다 하나뒤에 위치 반환할때
		if (loc == 0) loc = 1; // 더 작은게 없어서 처음위치가 반환될때 앞뒤 비교를 위해

		if (i == loc) continue;
		if (abs(arr[i] + arr[loc]) < mina) {
			mina = abs(arr[i] + arr[loc]);
			left = arr[i]; right = arr[loc];
		}
		
		if (i == loc - 1) continue;
		else if (abs(arr[i] + arr[loc - 1]) < mina) {
			mina = abs(arr[i] + arr[loc - 1]);
			left = arr[i]; right = arr[loc - 1];
		}	
	}
	cout << min(left, right) << " " << max(left, right) << "\n";

}

int main() {
	input();

	sort(arr, arr + N);

	//solve1은 처음에 제출한 투포인터
	//solve1();

	//solve2는 참고한 투포인터
	//solve2();

	//solve3는 이분탐색
	solve3();
	
	return 0;
}