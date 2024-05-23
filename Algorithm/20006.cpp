#include<bits/stdc++.h>
using namespace std;
typedef pair<int, string> pr;

// 2024.05.23
// Written by JongTKim

// 푼 방법 : 자료구조, 구현, 시뮬레이션

int P, M, num; 
string str;
vector<vector<pr>> vec;

bool cmp(const pr &A, const pr &B) {
	return A.second < B.second;
}

int main() {
	cin >> P >> M;
	for (int i = 0; i < P; i++) {
		cin >> num >> str;
		int flag = 0;
		for (vector<pair<int, string>>& vec2 : vec) {
			if (num > vec2[0].first + 10 || num < vec2[0].first - 10 || vec2.size() >= M) continue; // 첫번째 요소보다 +-10 밖이거나, 이미 팀이 꽉찼으면
			vec2.push_back({ num, str });
			flag = 1; 
			break;
		}
		if (flag == 0) { // 어느 팀이든 참가하지 못했음. 새 팀을 생성해서 넣어줘야함
			vector<pair<int, string>> v = {{num,str}};
			vec.push_back(v);
		}
	}

	for (vector<pr> &vec2 : vec) {
		if (vec2.size() == M) 
			cout << "Started!" << "\n"; // 인원이 꽉찼다면 시작된 팀이다
		else 
			cout << "Waiting!" << "\n";

		sort(vec2.begin(), vec2.end(), cmp);

		for (pr &pr : vec2) 
			cout << pr.first << " " << pr.second << "\n";
	}

	return 0;
}