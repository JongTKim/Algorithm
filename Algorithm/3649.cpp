#include<bits/stdc++.h>

using namespace std;

int arr[1000001];

int main() {
	int x; // 구멍의 너비
	int n; // 레고 조각의 수
	int fmax = 0;
	pair<int, int> pr;
	cin >> x >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	// 정렬됐으니깐 이제 투포인터 잡아서 찾으면됨

	int start = 0, end = n - 1;
	while (start < end) {
		if (arr[start] + arr[end] > x) {
			end--;
		}
		else if (arr[start] + arr[end] < x) {
			start++;
		}
		else { // 같은경우
			if (abs(arr[start] - arr[end]) > fmax) {
				fmax = abs(arr[start] - arr[end]);
				pr = { arr[start], arr[end] };
			}
			start++;
			end--;
		}
	}

	cout << pr.first << pr.second << "\n";
	return 0;
}