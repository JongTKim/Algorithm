#include<bits/stdc++.h>
using namespace std;
	
// 2024.04.01
// Writen by JongTKim

// Ǭ ��� : ������ psum
int a[100003];
int psum[100003] = { 0 };

int main() {

	int N, K;
	int maxsum = -100000010; 
	// ������ : ��ΰ� -100�̰� 10������ ���Ҽ������Ƿ� -1000�� ���Ͽ�����.
	// �׻� min, max���� �������� �־��� ������ ���� �� �����ؾ���

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		psum[i] = a[i] + psum[i - 1];
	}

	// �Է°� ���ÿ� ������ �迭 psum ����

	for (int i = K; i <= N; i++) {
		maxsum = max(maxsum, psum[i] - psum[i - K]);
	}

	cout << maxsum << "\n";

	return 0;
}