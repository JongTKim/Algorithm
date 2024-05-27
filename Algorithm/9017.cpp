#include<bits/stdc++.h>
using namespace std;

// 2024.05.27
// Written by JongTKim

// 푼 방법 : 구현

int T, N;
int scorecnt[201];
int score[201][2];
int num;

int main() {
	cin >> T;
	while (T--) {
		memset(scorecnt, 0, sizeof(scorecnt));
		memset(score, 0, sizeof(score));
		vector<int> v;
		map<int, int> mp;
		cin >> N;

		for (int i = 1; i <= N; i++) {
			cin >> num;
			v.push_back(num);
			mp[num]++;
		}
		int cnt = 1;
		for (int i : v) {
			if (mp[i] == 6) {
				if (scorecnt[i] == 4) score[i][1] += cnt;
				if (scorecnt[i] < 4) score[i][0] += cnt;
				scorecnt[i]++,cnt++;
			}
		}

		int mmin = 9999999, mcnt = 1;

		for (int i = 1; i <= 200; i++) {
			if (mp[i] != 6) continue;
			if (mmin > score[i][0]) { // 두 팀의 점수가 같을경우 다섯번째 결승점 통과 선수 고려
				mmin = score[i][0], mcnt = i;
			}
			else if (mmin == score[i][0]) {
				if (score[mcnt][1] > score[i][1]) {
					mcnt = i;
				}
			}
		}

		cout << mcnt << "\n";
	}
	return 0;
}