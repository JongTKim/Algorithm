#include<bits/stdc++.h>
using namespace std;

// 2024.04.25
// Writen by JongTKim

// 푼 방법 : DP, 슬라이딩 윈도우

int N, bdp[3], sdp[3];
int num1, num2, num3;
int mmax, mmin=999999;
int tmp, tmp1, tmp2;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num1 >> num2 >> num3;

		tmp = bdp[0]; tmp1 = bdp[1]; tmp2 = bdp[2];
		bdp[0] = max(tmp, tmp1) + num1;
		bdp[1] = max(max(tmp, tmp1), tmp2) + num2;
		bdp[2] = max(tmp1, tmp2) + num3;

		tmp = sdp[0]; tmp1 = sdp[1]; tmp2 = sdp[2];
		sdp[0] = min(tmp, tmp1) + num1;
		sdp[1] = min(min(tmp, tmp1), tmp2) + num2;
		sdp[2] = min(tmp1, tmp2) + num3;
	}
	for (int i = 0; i < 3; i++) {
		mmax = max(mmax, bdp[i]); 
		mmin = min(mmin, sdp[i]);
	}
	cout << mmax << " " << mmin << "\n";
	return 0;
}