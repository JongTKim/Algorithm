#include<bits/stdc++.h>
using namespace std;
	
// 2024.04.01
// Writen by JongTKim

// 푼 방법 : 누적합 psum
int a[100003];
int psum[100003] = { 0 };

int main() {

	int N, K;
	int maxsum = -100000010; 
	// 주의점 : 모두가 -100이고 10만개를 더할수있으므로 -1000만 이하여야함.
	// 항상 min, max값은 문제에서 주어진 범위를 보고 잘 설정해야함

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		psum[i] = a[i] + psum[i - 1];
	}

	// 입력과 동시에 누적합 배열 psum 생성

	for (int i = K; i <= N; i++) {
		maxsum = max(maxsum, psum[i] - psum[i - K]);
	}

	cout << maxsum << "\n";

	return 0;
}