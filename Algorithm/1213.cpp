#include<bits/stdc++.h>
using namespace std;

// 2024.04.01
// Writen by JongTKim

// 푼 방법 : 문자열
int main() {

	string str, fin;
	char mid = NULL;
	int arr[26] = { 0 };
	int cnt = 0;

	cin >> str;

	for (char c : str) {
		arr[c - 'A']++;
	}

	// 핵심 : Z부터 추가해나가야 마지막에는 사전순이된다(마지막에 A가 양쪽에 붙게되므로)
	// 로직 : 일단 홀수인 알파벳이 한개를 초과하면 무조건 X
	//		  홀수인게 하나일때는 하나는 마지막에 가운데에 넣어주고 -1한 값은 짝수니 짝수처럼 취급해서 양쪽에 붙여줌
	for (int i = 25; i >= 0; i--) {
		if (arr[i] & 1) { // 홀수면
			if (cnt) {
				cout << "I'm Sorry Hansoo";
				exit(0);
			}
			mid = char(i + 'A');
			arr[i]--;
			cnt++;
		}
		for (int j = 0; j < (arr[i] / 2); j++) {
			fin = char(i + 'A') + fin; // 앞뒤에 하나씩 넣어주기 
			fin += char(i + 'A');
		}
	}
	if(mid)
		fin.insert(fin.begin() + fin.size() / 2, mid);
	cout << fin << "\n";
	return 0;
}