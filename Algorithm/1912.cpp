#include<bits/stdc++.h>
using namespace std;

// 2024.04.09
// Writen by JongTKim

// 푼 방법 : DP

int N;
int arr[100003];
int psum[100003];
int maxsum = -2000;

// 이 문제는 N의 범위가 10만까지로 psum 배열로 해결하게 된다면 
// O(n^2/2)의 시간복잡도를 가지게 되어 시간초과가 나게된다
// 따라서 DP로 해결해야 한다,
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = max(psum[i - 1] + arr[i], arr[i]); 
		// 직전까지의 합이 0보다 작으면 굳이 더할필요가 없다. 
		// 예를들어 1 -2 5 3 일때 5가 입력될때 max(-1+5, 5)는 5를 선택하게 만든다.
		// 근데 만약 4 -2 5 3 이라면 5가 입력될떄 max(2+5, 5)는 7을 선택하게 만든다.
		maxsum = max(maxsum, psum[i]);
	}

	cout << maxsum << "\n";
	return 0;
}