#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

int N;
int arr[100001];
int Q, num;
pr qrr[1000001];

bool cmp(pr a, pr b) {
	return a.second < b.second;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> num;
		qrr[i] = { num, i };
	}

	sort(qrr, qrr + Q); // 첫번째 요소 오름차순

	int len = 0;
	for (int i = 0; i < Q; i++) {
		qrr[i].first -= len;
		while (true) {
			if (qrr[i].first > arr[len]) { // 못들어갈때 다음으로 넘어간다.
				len++;
				qrr[i].first--;
			}
			else { // 들어갈수있을때
				qrr[i].first = len;
				break;
			}
		}
	}

	sort(qrr, qrr + Q, cmp);

	for (int i = 0; i < Q; i++) {
		cout << qrr[i].first + 1 << " ";
	}

	return 0;

}