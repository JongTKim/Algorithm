#include<bits/stdc++.h>
using namespace std;

// 2024.05.09
// Written by JongTKim

// 푼 방법 : 구현


int T;
int n, k, t, m;
int id, num, score;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {


		cin >> n >> k >> t >> m;

		int arr[101][101] = { 0 }; // 각 팀의 문제별 점수가 들어가는곳. 1번팀 2번 문제의 점수 arr[1][2]
		int last[101] = { 0 }; // 각 팀의 마지막 제출 시간
		int tsum[101] = { 0 }; // 각 팀의 총 점수
		int ccount[101] = { 0 }; // 각 팀의 제출횟수
		int rrank = 1;

		for (int i = 1; i <= m; i++) {
			cin >> id >> num >> score;
			if (arr[id][num]) { // 이미 풀었던 문제면?
				if (score > arr[id][num]) {
					tsum[id] += (score - arr[id][num]);
					arr[id][num] = score;
				}
			}
			else { // 안 풀었던 문제라면?
				arr[id][num] = score;
				tsum[id] += score;
			}
			ccount[id]++; // 제출횟수 기록
			last[id] = i; // 마지막 제출 시간 기록
		}

		for (int i = 1; i <= n; i++) {	// 입력완료 이제 순위 출력
			if (i == t) continue; // 자기팀은 순위 비교 대상 제외
			if (tsum[i] > tsum[t]) rrank++;
			if (tsum[i] == tsum[t]) {
				if (ccount[i] < ccount[t]) rrank++;
				if (ccount[i] == ccount[t])
					if (last[i] < last[t]) rrank++;
			}
		}
		cout << rrank << "\n";
	}

	return 0;
}