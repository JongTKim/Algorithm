/*
#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100000+1


// 2024.04.26
// Writen by JongTKim

// Ǭ ��� : BFS + �켱���� ť, Deque(0-1 BFS)
// ���߿��

int N, K;
bool visited[MAX_SIZE];

int bfs(int start) {
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
	// �ð� �켱 ������ ���� �켱���� ť ���. 
	// �� ���� ���� ��� �ð��� �þ�� �ʴ°��(2*X)�� �ֱ⶧���� �켱���� ť�� �ʿ��ϴ�.
	// ���� ��� pair{�ð�, ������ġ} -> �ð������� �������� ����

	pq.push({ 0, start });

	visited[start] = 1;

	while (!pq.empty()) {

		int loc = pq.top().second; 
		int time = pq.top().first;

		pq.pop();

		if (loc == K) return time; // ���� ��ġ�� �����ߴٸ� �׶��� �ð� Return

		// *2 �� ���� üũ�ؾ��ϴ� ����? -> 1�϶� +1�̳� *2�� �Ȱ��� 2�ε�
		// +1�� ���� �ϰԵȴٸ�, visited[2]�� ä�����鼭 *2�� �� ���� ����ġ�� �����ϰԵ�

		if (loc * 2 < MAX_SIZE && loc * 2 < K * 2 && !visited[loc * 2]) { // *2 �ϱ����� ����Ȯ��, loc*2 < K*2 ������ �׸���
			visited[loc * 2] = 1;
			pq.push({ time, loc * 2 });
		}

		if (loc + 1 < MAX_SIZE && loc + 1 < K && !visited[loc+1]) { // +1 �ϱ����� ����Ȯ��, loc < K ������ �׸���
			visited[loc + 1] = 1;
			pq.push({ time + 1, loc + 1 });
		}

		if (loc - 1 >= 0 && !visited[loc-1]) { // -1 �ϱ����� ����Ȯ��
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
deque<pair<int, int>> dq; // Deque�� Priority Queue�� ���� ȿ���� �ش�.
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

		// ****  �� ������ ****
		// 0-1 BFS�� Deque�� �����Ҷ��� ����(-1�� ��츦 +1���� �����ؾ��Ѵ�)�� �� ����ϰų� 
		// �湮ó���� Deque���� pop�Ҷ� �ؾ��Ѵ�.
		if (loc * 2 < MAX_SIZE && loc * 2 < K * 2 && !visited[loc * 2]) dq.push_front({ loc * 2, time });
		if (loc + 1 < MAX_SIZE && loc + 1 <= K && !visited[loc + 1]) dq.push_back({ loc + 1, time + 1 });
		if (loc - 1 >= 0 && !visited[loc - 1]) dq.push_back({ loc - 1, time + 1 });
	}
	return 0;
}