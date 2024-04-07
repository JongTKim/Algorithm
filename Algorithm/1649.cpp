#include<bits/stdc++.h>
using namespace std;

int arr[205][205]; // 도시 연결 배열
int plan[1005]; // 여행 계획 배열
vector<int> vec[205]; // 갈수있는 도시의 리스트
bool visited[205];
int flag;

void dfs(int city1, int city2) {
	
	if (flag) return;

	for (int city : vec[city1]) {
		if (arr[city][city2]) { // 만약 연결해서 갈수있다면
			arr[city1][city2] = 1;
			arr[city2][city1] = 1;
			flag = 1;
			return;
		}
		else
			if (!visited[city]) {
				visited[city] = true; 
				dfs(city, city2);
			}
	}
	return;
}

int main() {
	int N; // 도시의 수
	int M; // 여행 계획에 속한 도시들의 수

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) vec[i].push_back(j); // i번째 도시에서 갈수있는 리스트 판단을 위해
		}
	}

	for (int i = 1; i <= N; i++) {
		arr[i][i] = 1;
	}

	for (int i = 0; i < M; i++) {
		cin >> plan[i];
	}

	for (int i = 0; i < M-1; i++) {
		flag = 0;
		fill(visited, visited + N, false);

		if (arr[plan[i]][plan[i + 1]]) // 이미 갈수있는곳이라면
			continue;

		else // 처음에 갈수없고 탐색을 해주어야 한다면
			dfs(plan[i], plan[i + 1]); // 예를들면 dfs(1,2) 이렇게 들어가게 된다

		if (flag == 1)
			continue;
		else {
			cout << "NO" << "\n";
			exit(0);
		}
	}

	cout << "YES" << "\n";


	return 0;

}