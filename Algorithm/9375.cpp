#include<bits/stdc++.h>
using namespace std;

// 2024.04.01
// Writen by JongTKim


// Ǭ ��� : ���շ�
// ���ڰ� 2����, ���ǰ� 2���������� 
// (���ھȾ�, ����1,����2) * (���ǾȾ�, ����1, ����2) = (n+1) * (m+1) = 9���� �����µ� 
// �� ��(���ھȾ�, ���ǾȾ�)�� �˸��� ��� �������� �����Ѵ� ������ �ϳ��� ���ָ� �ȴ�
int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		int n, max=1;
		string name, cat; 
		map<string, int> mt;

		cin >> n;

		while (n--) {
			cin >> name >> cat;
			mt[cat]++;
		}

		for (pair<string, int> pr : mt) {
			max *= (pr.second+1);
		}

		cout << max - 1 << "\n";
	}
	return 0;
}