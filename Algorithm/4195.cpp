#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// 2024.04.09
// Writen by JongTKim

// Ǭ ��� : ���Ͽ� ���ε�, ���� ����� String ����
int fr[200010]; // union-find �θ� ���
int pr[200010]; // �θ� ����� �׷����� ����

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
	// ���� �̹� ���� �θ�(���� �׷���)�� �ٲ�°� ����.
}

int findparent(int a, int b) {
	a = getparent(a);
	b = getparent(b);
	if (a == b) return pr[a];
	return pr[a] + pr[b]; // �� ����� �θ� �ٸ���� ��
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); //����� ���� ����
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
			if (mp.find(fr1) == mp.end()) mp[fr1] = ++count; // ó�� ������ �̸��� ���
			if (mp.find(fr2) == mp.end()) mp[fr2] = ++count; // ó�� ������ �̸��� ���
			unionparent(mp[fr1], mp[fr2]);
			cout << pr[getparent(mp[fr1])] << "\n";
		}
	}
	return 0;
}