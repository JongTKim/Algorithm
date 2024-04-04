#include<bits/stdc++.h>

using namespace std;

int arr[1000001];

int main() {
	int x; // ������ �ʺ�
	int n; // ���� ������ ��
	int fmax = 0;
	pair<int, int> pr;
	cin >> x >> n;
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
			start++;
			end--;
		}
	}

	cout << pr.first << pr.second << "\n";
	return 0;
}