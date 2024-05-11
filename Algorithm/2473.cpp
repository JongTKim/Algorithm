#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// 2024.05.11
// Written by JongTKim

// 푼 방법 : 투포인터

ll N;
ll arr[5001];
ll ans[3];

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void solve() {
	ll mmin = 3000000001;
	
	for (ll i = 0; i < N-2; i++) {
		ll left = i + 1, right = N - 1;
		ll mleft = 0, mright = 0;
		while (left < right) {
			ll ssum = arr[i] + arr[left] + arr[right];
			if (ssum == 0) {
				cout << arr[i] << " " << arr[left] << " " << arr[right] << "\n";
				exit(0);
			}
			else {
				if (mmin > llabs(ssum)) { // 갱신되는경우
					mmin = llabs(ssum);
					ans[0] = arr[i], ans[1] = arr[left], ans[2] = arr[right];
				}
				if (ssum < 0) left++;
				else right--;
			}
		}
	}
	sort(ans, ans + 3);
	cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
}

int main() {
	input();

	sort(arr, arr + N);

	solve();

	return 0;
}