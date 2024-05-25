#include<bits/stdc++.h>
using namespace std;

// 2024.05.05
// Written by JongTKim

// Ǭ ��� : �׸���, �ڷᱸ��
// �ڡ��߿�ڡ�
// �ڿ������� �������� ���̵� �߿��ϴ�

int T, N;
int arr[1000001];


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;

	while (T--) {
		map<int, int> mp;
		vector<int> vec2;
		long long fsum = 0;

		cin >> N;

		fill(arr, arr + N, 0);

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			mp[arr[i]]++;
		}

		for (int i = 0; i < N; i++) {
			if (arr[i] == mp.rbegin()->first) {
				int m = mp.rbegin()->first;
				mp[m]--;
				if (mp[m] == 0) mp.erase(m);

				//sort(vec2.begin(), vec2.end(), greater<>()); // ��������

				for (int c : vec2) {
					fsum += (arr[i] - c);
					mp[c]--;
					if (mp[c] == 0) mp.erase(c);
				}
				vec2.clear();
			}
			else {
				vec2.push_back(arr[i]);
			}
		}
		cout << fsum << "\n";
	}
	return 0;
}