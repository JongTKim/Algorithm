#include<bits/stdc++.h>
using namespace std;

// 2024.04.04
// Writen by JongTKim
// 푼 방법 : 투포인터

int arr[1000001];
// 수정된 코드 (불필요한 부분 제거)
int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int x; // 구멍의 너비
	int n; // 레고 조각의 수

	while (cin >> x) {
		cin >> n;
		x *= 10000000; // cm -> nm 단위일치 시키기

		int fmax = -1, flag = 0;

		for (int i = 0; i < n; i++) cin >> arr[i];

		sort(arr, arr + n);

		int start = 0, end = n - 1, mid;
		while (start <= end) {
			mid = (start + end) / 2;
			if (arr[i] + arr[mid] < x) {

			}
			if (arr[start] + arr[end] > x) end--;
			else if (arr[start] + arr[end] < x) start++;
			else break;
			// 두 조각의 합이 구멍의 너비와 일치하면 break
			// 생각해보면, 여러가지 경우가 존재할수 있으나, 처음의 경우보다 절댓값이 더 작아질수없다
		}
		if (start < end) cout << "yes " << arr[start] << " " << arr[end] << "\n";
		else cout << "danger" << "\n";
	}
	return 0;
}
