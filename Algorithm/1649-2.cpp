#include<bits/stdc++.h>
using namespace std;

int city[205];
int arr[205][205];
int plan[1005]; // ���� ��ȹ �迭
vector<int> vec;

int getparent(int x) {
	if (city[x] == x) return x;
	return getparent(city[x]);
}

void unionparent(int a, int b) {
	a = getparent(a);
	b = getparent(b);
	if (a < b) city[b] = a;
	else if (a == b) return;
	else city[a] = b;
}

int findparent(int a, int b) {
	a = getparent(a);
	b = getparent(b);
	if (a == b) return 1;
	return 0;
}

int main() {
	int N, M;
	
	// ���� ��, ��ȹ �� �Է�
	cin >> N >> M;
	vec.resize(N + 1, 0);

	// union-find �⺻ (�߿� : ���������� ���� �Է��ϸ� �ȵ�)
	for (int i = 1; i <= N; i++) {
		city[i] = i;
	}

	// ���� �������� �Է�
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) unionparent(i, j);
		}
	}

	// ��ȹ �Է�
	for (int i = 0; i < M; i++) cin >> plan[i];

	// ��ȹ �������� �Ǵ�
	for (int i = 0; i < M - 1; i++) {
		if (findparent(plan[i], plan[i + 1])) // �� �� ������ �θ� ������ Ȯ���Ѵ�.
			continue;
		else {
			cout << "NO" << "\n";
			exit(0);
		}
	}

	cout << "YES" << "\n";
	return 0;

}