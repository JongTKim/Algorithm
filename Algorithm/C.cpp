#include<bits/stdc++.h>
using namespace std;

int N, Q;
int l, r;
string str;

int solve(string &mstr) {
	int len = mstr.length();
	int ccnt = 0; // 이 문자열을 여러 방법으로 잘랐을때 최대 같은 문자
	for (int i = 1; i < len; i++) { // 서로 이웃한 문자 사이이므로 처음이랑 끝은 안된다.
		int cnt = 0; // 한번 잘랐을때 같은 문자열의 개수
		int num = 1; // num을 키워가며 양옆으로 뻗어나간다
		while (i-num >= 0 && i+num-1 < len) {
			char left = mstr[i - num]; // 좌측문자
			char right = mstr[i + num - 1]; // 우측문자
			if (left == right) cnt++;
			num++;
		}
		ccnt = max(ccnt, cnt);
	}
	return ccnt;
}

int main() {
	cin >> N >> str >> Q;
	for (int i = 0; i < Q; i++) {
		string mstr;
		cin >> l >> r;
		mstr = str.substr(l-1, r-l+1); // 문자열 자르기
		cout << solve(mstr) << "\n";
	}
	return 0;
}