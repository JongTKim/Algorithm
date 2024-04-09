#include<bits/stdc++.h>
using namespace std;

// 2024.04.09
// Writen by JongTKim

// Ǭ ��� : DP

int N;
int arr[100003];
int psum[100003];
int maxsum = -2000;

// �� ������ N�� ������ 10�������� psum �迭�� �ذ��ϰ� �ȴٸ� 
// O(n^2/2)�� �ð����⵵�� ������ �Ǿ� �ð��ʰ��� ���Եȴ�
// ���� DP�� �ذ��ؾ� �Ѵ�,
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = max(psum[i - 1] + arr[i], arr[i]); 
		// ���������� ���� 0���� ������ ���� �����ʿ䰡 ����. 
		// ������� 1 -2 5 3 �϶� 5�� �Էµɶ� max(-1+5, 5)�� 5�� �����ϰ� �����.
		// �ٵ� ���� 4 -2 5 3 �̶�� 5�� �Էµɋ� max(2+5, 5)�� 7�� �����ϰ� �����.
		maxsum = max(maxsum, psum[i]);
	}

	cout << maxsum << "\n";
	return 0;
}