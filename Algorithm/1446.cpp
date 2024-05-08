#include<bits/stdc++.h>
using namespace std;

// 2024.05.08
// Written by JongTKim

// Ǭ ��� : �ִܰ��, DP

int N, D;
int arr[10001]; // DP �迭
int st, en, len;
struct ji { int st, en, len; };
ji arr2[12];
// --- solve 1 ---
vector<pair<int, int>> sc[10001];
int dp[10001];
// --- solve 2 ---
 

// ���߿�� �� �����½ð��� ���� ������ ������ �ؾ��ұ�? 
// cmp�� cmp2�� �������� �� �˾Ƶ���

bool cmp(ji A, ji B) {
	if (A.en == B.en) return A.st < B.st ;
	else return A.en < B.en;
}

bool cmp2(ji A, ji B) {
	if (A.st == B.st) return A.en < B.en;
	else return A.st < B.st;
}


void input(){
	cin >> N >> D;
	for (int i = 1; i <= D; i++) 
		arr[i] = i; // DP �迭 �ʱ�ȭ
	for (int i = 0; i < N; i++) 
		cin >> arr2[i].st >> arr2[i].en >> arr2[i].len;
}

void solve1() {
	input();
	sort(arr2, arr2 + N, cmp);
	for (int i = 0; i < N; i++) {
		st = arr2[i].st, en = arr2[i].en, len = arr2[i].len;
		if (en <= D) { // ������ �ȵǴϱ� D���� ũ�� X
			if (arr[en] > arr[st] + len) {
				arr[en] = arr[st] + len;
				for (int j = en + 1; j <= D; j++) {
					arr[j] = arr[j - 1] + 1;
				}
			}
		}
	}
	cout << arr[D] << "\n";
}

void solve2() {
	
	fill(dp, dp + 10001, 10001);
	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		cin >> st >> en >> len;
		sc[en].push_back({ st, len });
	}
	dp[0] = 0;
	for (int i = 1; i <= D; i++) {
		if (sc[i].empty()) dp[i] = dp[i - 1] + 1;
		else {
			for (pair<int,int> pr : sc[i]) {
				dp[i] = min(dp[i],min(dp[i - 1] + 1, dp[pr.first] + pr.second));
				// dp[i]�� �� �ѹ� min�� ����ϴ� ������ sc[i]�� ���� �������� ��츦 ���
				// ��, ������ġ�� ���� �������� �������� ��츦 ����Ѱ���
				// {���,����,����}�� {0,5,1} {0,5,2}�� ���� ������� ù�������� ���õǾ�߰���?
			}
		}
	}
	cout << dp[D] << "\n";
}
int main() {
	//solve1();
	solve2();
	return 0;
}