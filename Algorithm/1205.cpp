#include<bits/stdc++.h>
using namespace std;

int N, num, P; 
// N => 리스트에 있는 점수 개수, num => 새로운 점수, P => 리스트에 올라 갈 수 있는 점수
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
		if (num < arr[i]) flag++; // 자신보다 큰것만 개수 측정
		if (num > arr[i]) break; // 자신보다 작은경우 뒤에는 전부 작은거니깐 break
		cnt++; // 자신이랑 같은것까지 cnt 측정
		// 즉, 자신이랑 같은수치는 flag에는 들어가지않지만, cnt에는 들어간다
	}
	
	if (cnt == P) flag = -1;

	cout << flag;
	return 0;
}