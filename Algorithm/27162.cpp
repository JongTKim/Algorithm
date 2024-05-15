#include<bits/stdc++.h>
using namespace std;

// 2024.05.12
// Written by JongTKim

// Ǭ ��� : ���Ʈ����, ���� ���� �б�, ����

bool ch[13]; int arr[7]; // ���ɿ���, ����
int num, msum;
char c;

void solve() {
	
	// -------------- ��Ѱ� �켱 ---------------
	if (ch[11]) { // Yacht
		for (int i = 1; i <= 6; i++) {
			if (arr[i] == 3) {
				msum = 50;
				return;
			}
		}
	}
	if (ch[10] && !arr[1]) { // Big Straight
		int flag = 0;
		for (int i = 2; i <= 6; i++) {
			if (arr[i] > 1) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			msum = 30;
			return;
		}
	}
	if (ch[9] && !arr[6]) { // Little Straight
		int flag = 0;
		for (int i = 1; i <= 5; i++) {
			if (arr[i] > 1) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			msum = 30;
			return;
		}
	}
	// -------------- ��Ѱ� �켱 ---------------

	for (int i = 1; i <= 6; i++) {
		if (ch[i]) // ���� �� ���� ��밡���ϸ�
			msum = max(msum, i * (arr[i] + 2));
	}

	if (ch[7]) { // Four of a Kind
		for (int i = 1; i <= 6; i++) {
			if (arr[i] >= 2) msum = max(msum, i * 4);
		}
	}

	if (ch[8]) { // Full House��
		for (int i = 1; i <= 6; i++) {
			if (arr[i] == 3) {
				if (i == 6) msum = max(msum, i * 3 + 10);
				else msum = max(msum, i * 3 + 12);
				break;
			}
			if (arr[i] == 2) {
				for (int j = 1; j <= 6; j++) {
					if (arr[j] == 1) {
						msum = max(msum, i * 2 + j * 3);
						msum = max(msum, i * 3 + j * 2);
					}
				}
			}
		}
	}
	if (ch[12]) { // Choice (6,6����)
		int sum = 0;
		for (int i = 1; i <= 6; i++) { // ���� ������ �� ���� ���Ѵ�
			if (arr[i]) sum += (i * arr[i]);
		}
		msum = max(msum, sum + 12);
	}

}

void input() {
	for (int i = 1; i <= 12; i++) {
		cin >> c;
		if (c == 'Y') ch[i] = true;
		else ch[i] = false;
	}
	for (int i = 0; i < 3; i++) {
		cin >> num;
		arr[num]++;
		// arr[1] = 2, arr[3] = 1
	}
}
int main() {
	input();
	solve();
	cout << msum << "\n";
	return 0;
}