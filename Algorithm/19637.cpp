#include<bits/stdc++.h>
using namespace std;

// 2024.05.19
// Written by JongTKim

// Ǭ ��� : �̺�Ž��

int N, M, num; // Īȣ�� ����, ����ؾ��ϴ� ĳ������ ����, �� ������
int power[100001];
string title[100001];

// �̺�Ž�� ����. Ž���Ҷ����� N���� ���� �˻��ϴ��� longN���� ���ϼ�����
// ���� O(NM)�̿��� �ð� ���⵵�� O(MlongN)���� ���ϼ��ִ�.
void solve2() {
	cin >> num;
	// �̺�Ž���� ���� ���������ʰ� lower_bound�� ����Ͽ� �ذ�.
	int idx = lower_bound(power, power + N, num) - power;
	cout << title[idx] << "\n";
}

void solve1() {
	cin >> num;
	int mid = 0, left = 0, right = N - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (num <= power[mid]) right = mid - 1; // ���� ��쵵 �� ������ ���� ���� Īȣ�� �ִ��� Ȯ��
		else left = mid + 1;
	}
	if (num > power[mid]) cout << title[mid + 1] << "\n";
	else cout << title[mid] << "\n";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> title[i] >> power[i];
	for (int i = 0; i < M; i++) solve1();
	return 0;
}