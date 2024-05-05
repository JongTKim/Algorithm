#include<bits/stdc++.h>
using namespace std;
#define EXP 500001

// 2024.05.05
// Written by JongTKim

// 푼 방법 : 그리디, 정렬

int N;
int arr[EXP];
int num;
long long ll;
int rrank = 1;
int maxn;

void input() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		maxn = max(maxn, num);
		arr[num]++;
	}
}

int main() {
	input();
	for (int i = 1; i <= maxn; i++) {
		while (arr[i] > 0) {
			ll += abs(i - rrank);
			rrank++;
			arr[i]--;
		}
	}
	cout << ll << "\n";
	return 0;
}