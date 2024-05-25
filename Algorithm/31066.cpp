#include<bits/stdc++.h>
using namespace std;

int T;
int N, M, K;

int main() {
	cin >> T;
	while (T--) {
		int cnt = 0;

		cin >> N >> M >> K;

		int num = M * K;

		if (num == 1) {
			if (N == 1) cnt = 1;
			else cnt = -1;
		}
		else if (N > num) {

			while (N > num) {
				N -= (num-1);
				cnt += 2;
			}
			cnt += 1;
		}
		else {
			cnt = 1;
		}
		cout << cnt << "\n";
	}
	return 0;
}