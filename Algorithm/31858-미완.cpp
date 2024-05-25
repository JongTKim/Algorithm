/*#include<bits/stdc++.h>
using namespace std;

int N, num, man;
int arr[200001];
long long ssum;
stack<pair<int, int>> st;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num;

		if (st.size()) {
			if (st.top().first > num && st.size() > 1) { 
				// 4 2 3 1 같은경우 1이 들어오면 4,2는 못쓰게 된다
				//ssum -= (st.size() - 1);
				ssum -= (st.size());
				ssum += 2;
				continue;
			}
			else if (st.top().first < num) { // 새로 들어온 숫자가 더 크다면
				while (!st.empty() && st.top().first < num) { // 스택이 비지않았고 작으면.
					ssum += (i - st.top().second);
					st.pop();
				}
			}
		}
		st.push({ num, i });
	}

	while (!st.empty()) {
		ssum += (N - st.top().second);
		st.pop();
	}

	cout << ssum << "\n";
	return 0;
}*/

#include<bits/stdc++.h>
using namespace std;

int N, num, cnt;
int arr[200001];
long long ssum;
stack<pair<int, int>> st;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num;

		if (st.size()) {
			if (st.top().first > num && st.size() > 1) {
				ssum -= (st.size() - 1);
			}
			else if (st.top().first < num) { // 새로 들어온 숫자가 더 크다면
				while (!st.empty() && st.top().first < num) { // 스택이 비지않았고 작으면.
					ssum += (i - st.top().second);
					st.pop();
				}
				cnt++;
			}
		}
		st.push({ num, i });
	}

	while (!st.empty()) {
		ssum += (N - st.top().second);
		st.pop();
	}

	cout << ssum << "\n";
	cout << cnt << "\n";
	return 0;
}