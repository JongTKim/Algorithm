#include<bits/stdc++.h>
using namespace std;

// 2024.05.06
// Written by JongTKim

// Ǭ ��� : �̺� Ž��, �Ű� ���� Ž��

int N, M;
int arr[10001];


void input() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> M;
	sort(arr, arr + N);
}

void solve1() {
	int maxn = arr[N - 1];

	if (maxn > M / N)
	{
		int cnt = M / N;
		int i = 0;

		for (i = 0; i < N; i++) {

			if (i == N - 1) break; // �������� ���������� 

			if (arr[i] <= cnt) M -= arr[i]; // ���Ѿ׺��� ���̹Ƿ� ��û�� �ݾ� �״�� �����Ҽ�����

			else { // ���� ū�� �������� cnt ��� �ٽõ�������
				cnt = M / (N - i);
				if (arr[i] > cnt) break;
				else i--;
			}
		}
		if (maxn > M / (N - i)) cout << M / (N - i) << "\n";
		else cout << maxn << "\n";
	}
	else
		cout << maxn << "\n";
}

void solve2() {
	int start = 0;
	int end = arr[N - 1];
	int result, sum;

	while (start <= end) {
		sum = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < N; i++) {
			sum += min(arr[i], mid);
			if (sum > M) break; // �ð� ����
		}
		if (M >= sum) result = mid, start = mid + 1;
		else end = mid - 1;
	}
	cout << result;
}
int main() {
	input(); // �Է�
	//solve1(); // �Ű� ���� Ž��
	solve2(); // �̺� Ž��
	return 0;
}