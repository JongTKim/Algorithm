#include<bits/stdc++.h>
using namespace std;

// 2024.04.19
// Writen by JongTKim

// 푼 방법 : 구현, 큐

int n, w, L;
int arr[1000];
int ans;
queue<int> q;


void input()
{
	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solution()
{
	int weight = 0;
	for (int i = 0; i < n; i++) {
		while (true) {
			if (q.size() == w) {
				weight -= q.front();
				q.pop();
			}
			if (arr[i] + weight <= L) {
				break;
			}
			q.push(0);
			ans++;
		}
		q.push(arr[i]);
		weight += arr[i];
		ans++;
	}
}

int main() {
	input();
	solution();
	cout << ans + w << "\n";
	return 0;
}