/*
#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100000+1


// 2024.04.26
// Writen by JongTKim

// 푼 방법 : BFS + 우선순위 큐, Deque(0-1 BFS)
// ★중요★

int N, K;
bool visited[MAX_SIZE];

int bfs(int start) {
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
	// 시간 우선 정렬을 위해 우선순위 큐 사용. 
	// 이 문제 같은 경우 시간이 늘어나지 않는경우(2*X)가 있기때문에 우선순위 큐가 필요하다.
	// 들어가는 양식 pair{시간, 현재위치} -> 시간순으로 오름차순 정렬

	pq.push({ 0, start });

	visited[start] = 1;

	while (!pq.empty()) {

		int loc = pq.top().second; 
		int time = pq.top().first;

		pq.pop();

		if (loc == K) return time; // 동생 위치에 도달했다면 그때의 시간 Return

		// *2 를 먼저 체크해야하는 이유? -> 1일때 +1이나 *2나 똑같은 2인데
		// +1을 먼저 하게된다면, visited[2]가 채워지면서 *2의 더 낮은 가중치를 무시하게됨

		if (loc * 2 < MAX_SIZE && loc * 2 < K * 2 && !visited[loc * 2]) { // *2 하기위한 조건확인, loc*2 < K*2 조건은 그리디
			visited[loc * 2] = 1;
			pq.push({ time, loc * 2 });
		}

		if (loc + 1 < MAX_SIZE && loc + 1 < K && !visited[loc+1]) { // +1 하기위한 조건확인, loc < K 조건은 그리디
			visited[loc + 1] = 1;
			pq.push({ time + 1, loc + 1 });
		}

		if (loc - 1 >= 0 && !visited[loc-1]) { // -1 하기위한 조건확인
			visited[loc - 1] = 1;
			pq.push({ time + 1, loc - 1 });
		}
	}


}
int main() {
	cin >> N >> K;
	
	cout << bfs(N) << "\n";

	return 0;
}
*/


#include<bits/stdc++.h>
#define MAX_SIZE 100000+1
using namespace std;

int N, K;
deque<pair<int, int>> dq; // Deque로 Priority Queue와 같은 효과를 준다.
int visited[MAX_SIZE];

int main() {
	cin >> N >> K;

	dq.push_back({ N, 0 });

	while (!dq.empty()) {
		int loc = dq.front().first;
		int time = dq.front().second;

		dq.pop_front();

		visited[loc] = 1;

		if (loc == K) {
			cout << time << "\n";
			break;
		}

		// ****  왕 주의점 ****
		// 0-1 BFS를 Deque로 구현할때는 순서(-1의 경우를 +1보다 먼저해야한다)를 잘 고려하거나 
		// 방문처리를 Deque에서 pop할때 해야한다.
		if (loc * 2 < MAX_SIZE && loc * 2 < K * 2 && !visited[loc * 2]) dq.push_front({ loc * 2, time });
		if (loc + 1 < MAX_SIZE && loc + 1 <= K && !visited[loc + 1]) dq.push_back({ loc + 1, time + 1 });
		if (loc - 1 >= 0 && !visited[loc - 1]) dq.push_back({ loc - 1, time + 1 });
	}
	return 0;
}