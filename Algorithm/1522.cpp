#include<bits/stdc++.h>
using namespace std;

// 2024.05.21
// Written by JongTKim

// Ǭ ��� : �����̵� ������

string str;
int anum; // a�� ����
int flag;
int mmin = 9999;

int main() {
	cin >> str;
	for (auto c : str)
		if (c == 'a') anum++;
	for (int i = 0; i < str.length(); i++) {
		flag = 0;
		for (int j = i; j < i + anum; j++) { // anum��ŭ �����̵� ������
			if (str[j % str.size()] == 'b') flag++;
		}
		mmin = min(mmin, flag);
	}
	cout << mmin << "\n";
	return 0;
}