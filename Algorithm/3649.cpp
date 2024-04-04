#include<bits/stdc++.h>
using namespace std;

// 2024.04.04
// Writen by JongTKim
// Ǭ ��� : ��������

int arr[1000001];
// ������ �ڵ� (���ʿ��� �κ� ����)
int main() {
	int x; // ������ �ʺ�
	int n; // ���� ������ ��

	while (cin >> x) {
		cin >> n;
		x *= 10000000; // cm -> nm ������ġ ��Ű��

		fill(arr, arr + n, 0);
		int fmax = -1, flag = 0;

		for (int i = 0; i < n; i++) cin >> arr[i];

		sort(arr, arr + n);

		int start = 0, end = n - 1;
		while (start < end) {
			if (arr[start] + arr[end] > x) end--;
			else if (arr[start] + arr[end] < x) start++;
			else break; 
			// �� ������ ���� ������ �ʺ�� ��ġ�ϸ� break
			// �����غ���, �������� ��찡 �����Ҽ� ������, ó���� ��캸�� ������ �� �۾���������
		}
		if (start < end) cout << "yes " << arr[start] << " " << arr[end] << "\n";
		else cout << "danger" << "\n";
	}
	return 0;
}


// ó���� �ۼ��ߴ� �ڵ�

/*
int main() {
	int x; // ������ �ʺ�
	int n; // ���� ������ ��

	while (cin >> x) {
		cin >> n;
		x *= 10000000;

		fill(arr, arr + n, 0);
		int fmax = -1;
		int flag = 0;
		pair<int, int> pr;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + n);
		// ���ĵ����ϱ� ���� �������� ��Ƽ� ã�����

		int start = 0, end = n - 1;
		while (start < end) {
			if (arr[start] + arr[end] > x) {
				end--;
			}
			else if (arr[start] + arr[end] < x) {
				start++;
			}
			else { // �������
				if (abs(arr[start] - arr[end]) > fmax) {
					fmax = abs(arr[start] - arr[end]);
					pr = { arr[start], arr[end] };
				}
				flag = 1;
				start++;
				end--;
			}
		}
		if (flag) cout << "yes ";
		else {
			cout << "danger" << "\n";
			continue;
		}
		cout << pr.first << " " << pr.second << "\n";
	}
	return 0;
}
*/