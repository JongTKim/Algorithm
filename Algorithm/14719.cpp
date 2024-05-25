#include<bits/stdc++.h>
using namespace std;

int H, W;
int arr[501];
int fsum,left, right, cur;

int main() {

	cin >> H >> W;

	for (int i = 0; i < W; i++) cin >> arr[i];

	for (int i = 1; i < W; i++) {
		int left = *max_element(arr, arr + i);
		int right = *max_element(arr + i + 1, arr + W);
		int cur = arr[i];
		if (cur < left && cur < right) fsum += min(left, right) - cur;
	}

	cout << fsum << "\n";
	return 0;
}