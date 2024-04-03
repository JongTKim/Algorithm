#include<bits/stdc++.h>
using namespace std;

int main() {

	int n, m, num, cnt = 0;

	cin >> n >> m; // n�� �����, m�� ���ϸ���

	priority_queue<int> point;

	for (int i = 0; i < n; i++)
	{
		int p, l; // p�� ������ ���, l�� ����
		cin >> p >> l;
		vector<int> v(p);

		for (int j = 0; j < p; j++) { // �Է� �κ�
			cin >> v[j];
		}

		if (p < l) { // ����, ������ ����� �� ��� ������ �ʿ䰡���ٸ�
			point.push(1);
		}
		else { // ������ ����� �� ���Ƽ� ������ �ʿ��ϴٸ�
			sort(v.begin(), v.end());
			point.push(v[p - l]);
		}
	}

	stack<int> st;

	while (!point.empty()) {
		st.push(point.top());
		point.pop();
	}

	while (!st.empty()) {
		if (m >= st.top()) {
			m -= st.top();
			st.pop();
			cnt++;
		}
		else {
			break;
		}
	}

	cout << cnt << "\n";

	return 0;
}