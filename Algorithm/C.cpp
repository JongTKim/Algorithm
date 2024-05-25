#include<bits/stdc++.h>
using namespace std;

int N, Q;
int l, r;
string str;

int solve(string &mstr) {
	int len = mstr.length();
	int ccnt = 0; // �� ���ڿ��� ���� ������� �߶����� �ִ� ���� ����
	for (int i = 1; i < len; i++) { // ���� �̿��� ���� �����̹Ƿ� ó���̶� ���� �ȵȴ�.
		int cnt = 0; // �ѹ� �߶����� ���� ���ڿ��� ����
		int num = 1; // num�� Ű������ �翷���� �������
		while (i-num >= 0 && i+num-1 < len) {
			char left = mstr[i - num]; // ��������
			char right = mstr[i + num - 1]; // ��������
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
		mstr = str.substr(l-1, r-l+1); // ���ڿ� �ڸ���
		cout << solve(mstr) << "\n";
	}
	return 0;
}