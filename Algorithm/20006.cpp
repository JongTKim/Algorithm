#include<bits/stdc++.h>
using namespace std;
typedef pair<int, string> pr;

// 2024.05.23
// Written by JongTKim

// Ǭ ��� : �ڷᱸ��, ����, �ùķ��̼�

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
			if (num > vec2[0].first + 10 || num < vec2[0].first - 10 || vec2.size() >= M) continue; // ù��° ��Һ��� +-10 ���̰ų�, �̹� ���� ��á����
			vec2.push_back({ num, str });
			flag = 1; 
			break;
		}
		if (flag == 0) { // ��� ���̵� �������� ������. �� ���� �����ؼ� �־������
			vector<pair<int, string>> v = {{num,str}};
			vec.push_back(v);
		}
	}

	for (vector<pr> &vec2 : vec) {
		if (vec2.size() == M) 
			cout << "Started!" << "\n"; // �ο��� ��á�ٸ� ���۵� ���̴�
		else 
			cout << "Waiting!" << "\n";

		sort(vec2.begin(), vec2.end(), cmp);

		for (pr &pr : vec2) 
			cout << pr.first << " " << pr.second << "\n";
	}

	return 0;
}