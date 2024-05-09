#include<bits/stdc++.h>
using namespace std;

// 2024.05.09
// Written by JongTKim

// 푼 방법 : 그리디

int N;
string str;
int maxc = 999999;

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> str;
}
int main() {

	input();
	int flag = 0, flag2 = 0;
	int count = 0, count2 = 0;
	char c = str[0];

	for (int i = 1; i < N; i++) {
		if (str[i] != c) count2++, flag = 1, flag2 = 1;
		else if (flag2) count++, flag = 0;
	}
	maxc = min(maxc, min(count, count2));

	flag = 0, flag2 = 0;
	count = 0, count2 = 0;
	c = str[N - 1];

	for (int i = N - 2; i >= 0; i--) {
		if (str[i] != c) count2++, flag = 1, flag2 = 1;
		else if (flag2) count++, flag = 0;
	}
	maxc = min(maxc, min(count2, count));

	cout << maxc << "\n";
	return 0;
}