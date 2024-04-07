#include<bits/stdc++.h>
using namespace std;

int arr[205][205]; // ���� ���� �迭
int plan[1005]; // ���� ��ȹ �迭
vector<int> vec[205]; // �����ִ� ������ ����Ʈ
bool visited[205];
int flag;

void dfs(int city1, int city2) {
	
	if (flag) return;

	for (int city : vec[city1]) {
		if (arr[city][city2]) { // ���� �����ؼ� �����ִٸ�
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
	int N; // ������ ��
	int M; // ���� ��ȹ�� ���� ���õ��� ��

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) vec[i].push_back(j); // i��° ���ÿ��� �����ִ� ����Ʈ �Ǵ��� ����
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

		if (arr[plan[i]][plan[i + 1]]) // �̹� �����ִ°��̶��
			continue;

		else // ó���� �������� Ž���� ���־�� �Ѵٸ�
			dfs(plan[i], plan[i + 1]); // ������� dfs(1,2) �̷��� ���� �ȴ�

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