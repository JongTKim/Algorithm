#include<bits/stdc++.h>
using namespace std;

int N; // ����ġ ����
int M; // �л� ��
int arr[101];
int ge, num;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> ge >> num;
		if (ge == 1) { // ���ڸ�
			for (int i = num; i <= N; i += num) arr[i] = !arr[i];
		}
		else { // ���ڸ�
			int i = 0;
			while (true) {
				if (num - i < 1 || num + i > N) break;
				if (arr[num - i] == arr[num + i]) i++;
				else break;
			}
			i--;
			for (int j = num - i; j <= num + i; j++) arr[j] = !arr[j];
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
		if (i % 20 == 0) cout << "\n";
	}
	return 0;
}