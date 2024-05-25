#include<bits/stdc++.h>
#define MAX_SIZE 100000+1
using namespace std;
typedef pair<int, int> pr;

struct compare {
	bool operator()(pr& A, pr& B) {
		return A.second > B.second;
	}
};
priority_queue<pr, vector<pr>, compare> pq;
int N, K;
int visited[MAX_SIZE];


int main() {
	cin >> N >> K;

	pq.push({ N, 0 });

	while (!pq.empty()) {
		int loc = pq.top().first;
		int time = pq.top().second;

		pq.pop();

		visited[loc] = 1;

		if (loc == K) {
			cout << time << "\n"; break;
		}

		if (loc + 1 < MAX_SIZE && loc + 1 <= K && !visited[loc + 1]) pq.push({ loc + 1,time + 1 });
		if (loc - 1 >= 0 && !visited[loc - 1]) pq.push({ loc - 1,time + 1 });
		if (loc * 2 < MAX_SIZE && loc * 2 < K * 2 && !visited[loc * 2]) pq.push({ loc * 2, time });
	}
	return 0;
}