#include<bits/stdc++.h>
using namespace std;

// 2024.05.05
// Written by JongTKim

// Ǭ ��� : ���ڿ�, �׸���

int main() {

	string str, test;
	int cnt = 0;
	int i = 0;

	getline(cin, str);
	getline(cin, test);

	while (true) {
		int pos = str.find(test, i) ;
		if (pos == string::npos) break; // ���̻� ������ break
		else i = pos + test.size();
		cnt++;
	}
	cout << cnt << "\n";
	return 0;
}