#include<bits/stdc++.h>
using namespace std;

int N, M;
int arr[100001];
long long cnt;
long long ssum;
long long fcnt = 1;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		ssum += arr[i]; // �� ��ǥ���� ����
	} 
	sort(arr, arr + N, greater<int>());

	if (ssum % 2) ssum = ssum / 2 + 1;
	else ssum = ssum / 2;

	for (int i = 0; i < N; i++) {
		cnt += arr[i];
		fcnt++;
		if (cnt >= ssum) break;
	}
	// ���� i������ ������ȴ�.

	cout << M / fcnt << "\n";
	return 0;

}