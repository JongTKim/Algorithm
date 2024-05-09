#include<bits/stdc++.h>
using namespace std;

// 2024.05.09
// Written by JongTKim

// Ǭ ��� : ����


int T;
int n, k, t, m;
int id, num, score;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {


		cin >> n >> k >> t >> m;

		int arr[101][101] = { 0 }; // �� ���� ������ ������ ���°�. 1���� 2�� ������ ���� arr[1][2]
		int last[101] = { 0 }; // �� ���� ������ ���� �ð�
		int tsum[101] = { 0 }; // �� ���� �� ����
		int ccount[101] = { 0 }; // �� ���� ����Ƚ��
		int rrank = 1;

		for (int i = 1; i <= m; i++) {
			cin >> id >> num >> score;
			if (arr[id][num]) { // �̹� Ǯ���� ������?
				if (score > arr[id][num]) {
					tsum[id] += (score - arr[id][num]);
					arr[id][num] = score;
				}
			}
			else { // �� Ǯ���� �������?
				arr[id][num] = score;
				tsum[id] += score;
			}
			ccount[id]++; // ����Ƚ�� ���
			last[id] = i; // ������ ���� �ð� ���
		}

		for (int i = 1; i <= n; i++) {	// �Է¿Ϸ� ���� ���� ���
			if (i == t) continue; // �ڱ����� ���� �� ��� ����
			if (tsum[i] > tsum[t]) rrank++;
			if (tsum[i] == tsum[t]) {
				if (ccount[i] < ccount[t]) rrank++;
				if (ccount[i] == ccount[t])
					if (last[i] < last[t]) rrank++;
			}
		}
		cout << rrank << "\n";
	}

	return 0;
}