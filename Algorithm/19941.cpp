#include<bits/stdc++.h>
using namespace std;

// 2024.05.06
// Written by JongTKim

// Ǭ ��� : �׸���

int N, K;
string str;
char ch[20001];
bool visited[20001];
int cnt;

int main() {
	cin >> N >> K;
	cin >> str;

	for (int i = 0; i < N; i++) {
		ch[i] = str[i];
	}
	
	for (int i = 0; i < N; i++) {
		if (ch[i] == 'P') { // ���� ����̸� �ܹ��� ã�ƾߵ�
			for (int j = i-K; j <= i+K; j++) { // ���� ����̸� �ܹ���ã��
				if (j < 0 || j > N) continue;
				if (ch[j] == 'H' && !visited[j]) {
					visited[j] = true;
					cnt++;
					break;
				}
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}