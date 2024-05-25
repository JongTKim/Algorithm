#include<bits/stdc++.h>
using namespace std;

int N, cnt;
string st,str;
int ch[30];

int main() {
	cin >> N;

	// 첫번째 입력
	cin >> st;
	for (int i = 0; i < st.length(); i++) {
		ch[st[i] - 'A']++;
	}

	// 그 후
	for (int i = 0; i < N - 1; i++) {
		int ch2[30] = { 0 };
		int sum = 0;
		cin >> str;
		for (int j = 0; j < str.length(); j++) ch2[str[j] - 'A']++;

		for (int j = 0; j < 30; j++) sum += abs(ch2[j] - ch[j]);

		if (st.length() == str.length()) {
			if (sum <= 2) cnt++;
		}
		else if (st.length() == str.length() + 1) {
			if (sum <= 1) cnt++;
		}
		else if (st.length() + 1 == str.length()) {
			if (sum <= 1) cnt++;
		}
		
	}
	cout << cnt << "\n";
	return 0;
}