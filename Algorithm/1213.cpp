#include<bits/stdc++.h>
using namespace std;

// 2024.04.01
// Writen by JongTKim

// Ǭ ��� : ���ڿ�
int main() {

	string str, fin;
	char mid = NULL;
	int arr[26] = { 0 };
	int cnt = 0;

	cin >> str;

	for (char c : str) {
		arr[c - 'A']++;
	}

	// �ٽ� : Z���� �߰��س����� ���������� �������̵ȴ�(�������� A�� ���ʿ� �ٰԵǹǷ�)
	// ���� : �ϴ� Ȧ���� ���ĺ��� �Ѱ��� �ʰ��ϸ� ������ X
	//		  Ȧ���ΰ� �ϳ��϶��� �ϳ��� �������� ����� �־��ְ� -1�� ���� ¦���� ¦��ó�� ����ؼ� ���ʿ� �ٿ���
	for (int i = 25; i >= 0; i--) {
		if (arr[i] & 1) { // Ȧ����
			if (cnt) {
				cout << "I'm Sorry Hansoo";
				exit(0);
			}
			mid = char(i + 'A');
			arr[i]--;
			cnt++;
		}
		for (int j = 0; j < (arr[i] / 2); j++) {
			fin = char(i + 'A') + fin; // �յڿ� �ϳ��� �־��ֱ� 
			fin += char(i + 'A');
		}
	}
	if(mid)
		fin.insert(fin.begin() + fin.size() / 2, mid);
	cout << fin << "\n";
	return 0;
}