#include<bits/stdc++.h>
using namespace std;

// 2024.05.06
// Written by JongTKim

// 푼 방법 : 그리디

int N, K;
string str;
char ch[20001];
bool visited[20001];
int cnt;

int main() {
	cin >> N >> K;
	cin >> str;

	for (int i = 0; i < N; i++) {
		ch[i] = str[i];
	}
	
	for (int i = 0; i < N; i++) {
		if (ch[i] == 'P') { // 만약 사람이면 햄버거 찾아야됨
			for (int j = i-K; j <= i+K; j++) { // 만약 사람이면 햄버거찾기
				if (j < 0 || j > N) continue;
				if (ch[j] == 'H' && !visited[j]) {
					visited[j] = true;
					cnt++;
					break;
				}
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}