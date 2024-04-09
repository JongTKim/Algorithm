#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// 2024.04.09
// Writen by JongTKim

// 푼 방법 : 유니온 파인드, 맵을 사용한 String 매핑
int fr[200010]; // union-find 부모 노드
int pr[200010]; // 부모에 연결된 그래프의 숫자

int getparent(int x) {
	if (fr[x] == x) return x;
	return getparent(fr[x]);
}

void unionparent(int a, int b) {
	a = getparent(a);
	b = getparent(b);
	if (a < b) {
		fr[b] = a;
		pr[a] += pr[b];
	}
	else if (a > b) {
		fr[a] = b;
		pr[b] += pr[a];
	}
	// 만약 이미 같은 부모(같은 그래프)면 바뀌는건 없다.
}

int findparent(int a, int b) {
	a = getparent(a);
	b = getparent(b);
	if (a == b) return pr[a];
	return pr[a] + pr[b]; // 두 사람의 부모가 다를경우 ㄱ
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); //입출력 묶음 해제
	cout.tie(NULL);

	int T;

	cin >> T;

	while (T--) {
		unordered_map<string, int> mp;

		int F, count = 0; 
		string fr1, fr2;
		cin >> F;
		for (int i = 1; i <= F * 2; i++) 
			fr[i] = i, pr[i] = 1;

		for (int i = 0; i < F; i++) {
			cin >> fr1 >> fr2;
			if (mp.find(fr1) == mp.end()) mp[fr1] = ++count; // 처음 들어오는 이름일 경우
			if (mp.find(fr2) == mp.end()) mp[fr2] = ++count; // 처음 들어오는 이름일 경우
			unionparent(mp[fr1], mp[fr2]);
			cout << pr[getparent(mp[fr1])] << "\n";
		}
	}
	return 0;
}