#include<bits/stdc++.h>
using namespace std;

int N, M;
int arr[1001];
int sum;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N, greater<>()); // �������� ����

	int cnt = N;
	for (int i = 0; i < M; i++) {
		if (arr[i] <= 0) break;
		if (cnt <= 0) break;
		else { sum += arr[i], cnt -= 2; }
	}


	/*
	int len = N - (upper_bound(arr, arr + N, 0) - arr); // 0���� ū ���� ��ִ°�?

	if (M >= len) { // ���� �� ���ų� ���������� 0���� ū���� �� ������������
		int num = N % 2 ? (N / 2) + 1 : N / 2;
		if (len > num) { // �ٸ�, ��뵵 ���������ϴϱ�
			for (int i = 0; i < num; i++) sum += arr[N - 1 - i];
		}
		else {
			for (int i = 0; i < len; i++) sum += arr[N - 1 - i];
		}
	}
	else { // ���� ���� �� ������? => �ϸ�ŭ�� ���������
		for (int i = 0; i < M; i++) sum += arr[N-1-i];
	}
	*/
	cout << sum << "\n";
	return 0;
}