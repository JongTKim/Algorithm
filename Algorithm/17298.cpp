#include<bits/stdc++.h>
using namespace std;

int A;
int arr[1000001];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> A;

	for (int i = 0; i < A; i++) cin >> arr[i];

	for (int i = 0; i < A; i++) {
		int a = upper_bound(arr + i, arr + A, arr[i]) - (arr + i);
		cout << arr[a] << " ";
	}
	return 0;
}