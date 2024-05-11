#include<bits/stdc++.h>
using namespace std;

// 2024.05.11
// Written by JongTKim

// Ǭ ��� : ��������, �̺�Ž��

int N;
int arr[100001];

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void solve1() {
	if (arr[0] > 0) { // ��ΰ� ���
		cout << arr[0] << " " << arr[1] << "\n"; // �������� ���
	}
	else if (arr[N - 1] < 0) { // ��ΰ� ����
		cout << arr[N - 2] << " " << arr[N - 1] << "\n"; // �������� ���
	}
	else { // ��� ���� �����ִ� �κ�
		int left = 0, right = 0;
		for (left = 0; left < N - 1; left++) {
			if (arr[left] < 0 && arr[left + 1] > 0) break;
		}
		right = left + 1;
		int mmax = abs(arr[right] + arr[left]);
		int mright = right, mleft = left;

		if (left > 0) { // -2 -1 10 �� ���
			if (abs(arr[left] + arr[left - 1]) < mmax) {
				mmax = abs(arr[left] + arr[left - 1]);
				mleft = left - 1, mright = left;
			}
		}

		if (right < N - 1) { // -10 1 2 �� ���
			if (abs(arr[right] + arr[right + 1]) < mmax) {
				mmax = abs(arr[right] + arr[right + 1]);
				mleft = right, mright = right + 1;
			}
		}

		while (left >= 0 && right < N) {
			if (arr[right] + arr[left] > 0) {
				if (abs(arr[right] + arr[left]) < mmax) {
					mmax = abs(arr[right] + arr[left]);
					mleft = left, mright = right;
				}
				left--;
			}
			else if (arr[right] + arr[left] == 0) {
				mleft = left, mright = right;
				break;
			}
			else {
				if (abs(arr[right] + arr[left]) < mmax) {
					mmax = abs(arr[right] + arr[left]);
					mleft = left, mright = right;
				}
				right++;
			}
		}
		cout << arr[mleft] << " " << arr[mright] << "\n";
	}
}

void solve2() {
	int left = 0, right = N - 1, min = 2000000000;
	int mleft = 0, mright = 0;

	while (left < right) {
		int sum = arr[left] + arr[right];

		if (sum == 0) {
			mleft = left, mright = right;
			break;
		}
		if (min > abs(sum)) { // ���ŵǴ°��
			min = abs(sum);
			mleft = left, mright = right;
		}
		if (sum < 0) left++;
		else right--;
	}
	cout << arr[mleft] << " " << arr[mright] << "\n";
}

void solve3() {
	int left, right, mina = 2000000000;

	for (int i = 0; i <= N - 1; i++) {
		int loc = lower_bound(arr, arr + N, -arr[i]) - arr; // �Ķ������ ������ ���ų� ū ó����ġ ��ȯ

		if (loc > N - 1) loc = N-1; // �� ū�Ծ�� ���������� �ϳ��ڿ� ��ġ ��ȯ�Ҷ�
		if (loc == 0) loc = 1; // �� ������ ��� ó����ġ�� ��ȯ�ɶ� �յ� �񱳸� ����

		if (i == loc) continue;
		if (abs(arr[i] + arr[loc]) < mina) {
			mina = abs(arr[i] + arr[loc]);
			left = arr[i]; right = arr[loc];
		}
		
		if (i == loc - 1) continue;
		else if (abs(arr[i] + arr[loc - 1]) < mina) {
			mina = abs(arr[i] + arr[loc - 1]);
			left = arr[i]; right = arr[loc - 1];
		}	
	}
	cout << min(left, right) << " " << max(left, right) << "\n";

}

int main() {
	input();

	sort(arr, arr + N);

	//solve1�� ó���� ������ ��������
	//solve1();

	//solve2�� ������ ��������
	//solve2();

	//solve3�� �̺�Ž��
	solve3();
	
	return 0;
}