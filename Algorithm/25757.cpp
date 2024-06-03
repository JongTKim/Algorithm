#include<bits/stdc++.h>
using namespace std;

// 2024.06.03
// Written by JongTKim

// Ç¬ ¹æ¹ý : ÇØ½Ã¸Ê, ¹®ÀÚ¿­

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	char game;
	set<string> s;

	cin >> N >> game;

	for (int i = 0; i < N; i++) {
		string str;

		cin >> str;
		s.insert(str);
	}

	if (game == 'Y')
		cout << s.size();
	else if (game == 'F')
		cout << s.size() / 2;
	else
		cout << s.size() / 3;

	return 0;
}