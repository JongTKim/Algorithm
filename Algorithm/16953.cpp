#include<bits/stdc++.h>
using namespace std;

int A, B, msum = 999999;

void solve(int num, int cnt) {
	if (A > num) return;
	if (A == num) msum = min(msum, cnt);
	if (num % 2 == 0) solve(num / 2, cnt + 1);
	if (num % 2 == 1) solve(num / 10, cnt + 1);
}

int main() {	
	cin >> A >> B;
	solve(B, 0);
	if (msum == 999999) cout << -1 << "\n";
	else cout << msum+1 << "\n";
	return 0;
}