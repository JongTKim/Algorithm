#include<bits/stdc++.h>
using namespace std;

int N, num, P; 
// N => ����Ʈ�� �ִ� ���� ����, num => ���ο� ����, P => ����Ʈ�� �ö� �� �� �ִ� ����
int arr[51];
int flag=1, cnt;

int main() {
	
	cin >> N >> num >> P;

	if (N == 0) {
		cout << 1 << "\n";
		return 0;
	}

	for (int i = 1; i <= N; i++) cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		if (num < arr[i]) flag++; // �ڽź��� ū�͸� ���� ����
		if (num > arr[i]) break; // �ڽź��� ������� �ڿ��� ���� �����Ŵϱ� break
		cnt++; // �ڽ��̶� �����ͱ��� cnt ����
		// ��, �ڽ��̶� ������ġ�� flag���� ����������, cnt���� ����
	}
	
	if (cnt == P) flag = -1;

	cout << flag;
	return 0;
}