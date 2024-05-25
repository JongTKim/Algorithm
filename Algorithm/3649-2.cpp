#include<bits/stdc++.h>
using namespace std;

// 2024.04.04
// Writen by JongTKim
// Ǭ ��� : ��������

int arr[1000001];
// ������ �ڵ� (���ʿ��� �κ� ����)
int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int x; // ������ �ʺ�
	int n; // ���� ������ ��

	while (cin >> x) {
		cin >> n;
		x *= 10000000; // cm -> nm ������ġ ��Ű��

		int fmax = -1, flag = 0;

		for (int i = 0; i < n; i++) cin >> arr[i];

		sort(arr, arr + n);

		int start = 0, end = n - 1, mid;
		while (start <= end) {
			mid = (start + end) / 2;
			if (arr[i] + arr[mid] < x) {

			}
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
