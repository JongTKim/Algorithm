#include<bits/stdc++.h>
using namespace std;

int main() {

	int n, m, num, cnt = 0;

	cin >> n >> m; // n은 과목수, m은 마일리지

	priority_queue<int> point;

	for (int i = 0; i < n; i++)
	{
		int p, l; // p는 듣고싶은 사람, l은 정원
		cin >> p >> l;
		vector<int> v(p);

		for (int j = 0; j < p; j++) { // 입력 부분
			cin >> v[j];
		}

		if (p < l) { // 만약, 듣고싶은 사람이 더 적어서 경쟁할 필요가없다면
			point.push(1);
		}
		else { // 듣고싶은 사람이 더 많아서 경쟁이 필요하다면
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