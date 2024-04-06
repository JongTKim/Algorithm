#include<bits/stdc++.h>
using namespace std;

// 2024.04.06
// Writen by JongTKim
// 푼 방법 : 구현, 완전탐색

int arr[505][505];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int fmax = 0;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	// 중요점 : 생각해보면, overflow, underflow 를 확인할 필요가없음
	// 왜냐하면, 어차피 4개 미만을 합친값은 최대값이 될수없기때문 
	// 따라서, 1부터 시작하여 arr[-1][]이 될수있는 경우를 제거해주고(arr[0][]은 가능) -> segmentation fault 요인 제거
	// arr[505][505]로 선언하여 -> undefined behavior 요인 제거

	for (int y = 1; y <= N; y++) { // y가 y축
		for (int x = 1; x <= M; x++) { // x가 x축
			int mmax = 0;
			mmax = max(mmax, arr[y + 1][x] + arr[y + 2][x] + arr[y + 3][x]); // 1번
			mmax = max(mmax, arr[y][x + 1] + arr[y][x + 2] + arr[y][x + 3]); // 2번
			mmax = max(mmax, arr[y][x + 1] + arr[y + 1][x] + arr[y + 1][x + 1]); // 3번
			mmax = max(mmax, arr[y + 1][x] + arr[y + 2][x] + arr[y + 2][x + 1]); // 4번
			mmax = max(mmax, arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x]); // 5번
			mmax = max(mmax, arr[y][x + 1] + arr[y + 1][x + 1] + arr[y + 2][x + 1]); // 6번
			mmax = max(mmax, arr[y][x + 1] + arr[y][x + 2] + arr[y-1][x + 2]); // 7번
			mmax = max(mmax, arr[y+1][x] + arr[y+1][x + 1] + arr[y + 2][x + 1]); // 8번
			mmax = max(mmax, arr[y][x + 1] + arr[y + 1][x] + arr[y+1][x-1]); // 9번
			mmax = max(mmax, arr[y][x-1] + arr[y+1][x-1] + arr[y-1][x]); // 10번
			mmax = max(mmax, arr[y][x + 1] + arr[y+1][x + 1] + arr[y + 1][x + 2]); // 11번
			mmax = max(mmax, arr[y][x+1] + arr[y][x + 2] + arr[y + 1][x + 1]); // 12번
			mmax = max(mmax, arr[y][x+1] + arr[y-1][x+1] + arr[y + 1][x + 1]); // 13번
			mmax = max(mmax, arr[y][x + 1] + arr[y][x + 2] + arr[y -1][x + 1]); // 14번
			mmax = max(mmax, arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x + 1]); // 15번
			mmax = max(mmax, arr[y][x+1] + arr[y][x + 2] + arr[y+1][x + 2]); // 16번
			mmax = max(mmax, arr[y + 1][x] + arr[y+1][x + 1] + arr[y + 1][x + 2]); // 17번
			mmax = max(mmax, arr[y + 1][x] + arr[y + 2][x] + arr[y][x + 1]); // 18번
			mmax = max(mmax, arr[y + 1][x] + arr[y+2][x] + arr[y + 2][x-1]); // 19번

			fmax = max(fmax, mmax + arr[y][x]);
		}
	}
	cout << fmax << "\n";
	return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;

int arr[505][505];

int main() {

	int N, M;
	int fmax = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int y = 0; y < N; y++) { // y가 y축
		for (int x = 0; x < M; x++) { // x가 x축
			if (y + 3 < N)
				fmax = max(fmax, arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 3][x]);
			if (x + 3 < M)
				fmax = max(fmax, arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y][x + 3]);
			if (y + 1 < N && x + 1 < M)
				fmax = max(fmax, arr[y][x] + arr[y][x + 1] + arr[y + 1][x] + arr[y + 1][x + 1]);
			if (y + 1 < N && x + 2 < M) {
				fmax = max(fmax, arr[y][x] + arr[y][x + 1] + arr[y][x+2] + arr[y + 1][x]); // 5번
				fmax = max(fmax, arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 1][x + 2] + arr[y][x + 2]); // 7번
				fmax = max(fmax, arr[y + 1][x] + arr[y + 1][x + 1] + arr[y][x+1] + arr[y][x + 2]); // 9번
				fmax = max(fmax, arr[y][x] + arr[y][x + 1] + arr[y + 1][x+1] + arr[y + 1][x + 2]); // 11번
				fmax = max(fmax, arr[y][x] + arr[y][x + 1] + arr[y + 1][x+1] + arr[y][x + 2]); // 12번
				fmax = max(fmax, arr[y+1][x] + arr[y+1][x + 1] + arr[y][x+1] + arr[y + 1][x + 2]); // 14번
				fmax = max(fmax, arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 2]); // 16번
				fmax = max(fmax, arr[y][x] + arr[y + 1][x] + arr[y+1][x + 1] + arr[y + 1][x + 2]); // 17번

			}
			if (y + 2 < N && x + 1 < M) {
				fmax = max(fmax, arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 2][x + 1]); // 4번
				fmax = max(fmax, arr[y][x] + arr[y][x + 1] + arr[y + 1][x+1] + arr[y + 2][x + 1]); // 6번
				fmax = max(fmax, arr[y][x] + arr[y+1][x + 1] + arr[y + 1][x] + arr[y + 2][x + 1]); // 8번
				fmax = max(fmax, arr[y+1][x] + arr[y+2][x] + arr[y + 1][x+1] + arr[y][x + 1]); // 10번
				fmax = max(fmax, arr[y+1][x] + arr[y+1][x + 1] + arr[y][x+1] + arr[y + 2][x + 1]); // 13번
				fmax = max(fmax, arr[y][x] + arr[y+1][x] + arr[y + 2][x] + arr[y + 1][x + 1]); // 15번
				fmax = max(fmax, arr[y][x] + arr[y + 1][x] + arr[y][x + 1] + arr[y + 2][x]); // 18번
				fmax = max(fmax, arr[y+2][x] + arr[y + 2][x + 1] + arr[y+1][x + 1] + arr[y][x + 1]); // 19번
			}
		}
	}
	cout << fmax << "\n";
	return 0;
}
*/
