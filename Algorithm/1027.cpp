#include<bits/stdc++.h>
using namespace std;

// 2024.04.08
// Writen by JongTKim

// 푼 방법 : 완전탐색, 수학
int height[55];
int b[55];

int main() {
	// 밑에보다 개선된 방안. 
	// 생각해보면 좌우를 나눠 계산할필요가없음.
	// 왼쪽 건물에서 오른쪽 높은건물이 보이는건, 오른쪽 건물에서도 왼쪽 건물을 볼 수 있다는 소리니
	// 계속 오른쪽만 탐색하면 된다. (이해필수)
	int N, num, fcnt = 0, j;
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> height[i];

	for (int i = 1; i <= N; i++) {
		double mmin = -1000000000, gr;
		for (int j = i + 1; j <= N; j++) {
			gr = (double)(height[i] - height[j]) / (i - j); // 기울기 구하기
			if (gr > mmin) mmin = gr, b[i]++, b[j]++;
		}
	}
	cout << *max_element(b, b + N + 1) << "\n";

	return 0;
}

/*#include<bits/stdc++.h>
using namespace std;

int height[55];
int b[55];

int main() {
	int N, num, fcnt = 0, j;
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> height[i];

	for (int i = 1; i <= N; i++) {
		j = i;
		double mmin = -1000000000, mmax = 1000000000, gr;
		int cnt = 0;
		while (j - 1 >= 1) { // 왼쪽으로 갈 수 있는지 확인
			j--;
			gr = (double)(height[i] - height[j]) / (i - j); // 기울기 구하기
			if (gr < mmax) mmax = gr, cnt++;
		}

		j = i;
		while (j + 1 <= N) { // 오른쪽으로 갈 수 있는지 확인
			j++;
			gr = (double)(height[i] - height[j]) / (i - j); // 기울기 구하기
			if (gr > mmin) mmin = gr, cnt++;
		}
		fcnt = max(fcnt, cnt);
	}
	cout << fcnt << "\n";
	//cout << *max_element(b,b+N) << "\n";

	return 0;
}*/