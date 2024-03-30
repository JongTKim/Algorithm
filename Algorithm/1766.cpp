#include<bits/stdc++.h>
using namespace std;
#define MAX 32001

// 2024.03.30
// Writen by JongTKim

int main() {

	// Ǭ���
	// �������� + �켱���� ť

	int N, M, A, B;
	int degree[MAX] = { 0 };

	vector<int> vec[MAX]; // ��ȣ���� Ǯ��� Ǯ���ִ� ������ �� vec[4]={1,2,3} �� ������ 4�������� 1,2,3�� �������� ���� Ǯ�����

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		vec[A].push_back(B);
		degree[B]++; // 2�� ���� �ϼ��� ���� �ڵ�, degree�� �����ϸ� ���� Ǯ��ߵ� ������ �ִٴ� �Ҹ���
	}
	// �Է¿Ϸ�

	priority_queue<int, vector<int>, greater<int>> pq; // 3�� ���� �ϼ��� ���� �ڵ�, �����Ѱ� ������ �־ ���� �������� Ǯ��ߵǴϱ� �������� ����

	for (int i = 1; i <= N; i++) {
		if (!degree[i]) pq.push(i); // degree�� �����ϴ°��� ���� ���� Ǯ �� �ִ� ������. ���� ������ ���� ���
	}

	while (!pq.empty()) {
		int solve = pq.top(); // �̹��� Ǯ ������ȣ
		pq.pop();

		cout << solve << " ";

		for (int i : vec[solve]) {
			degree[i]--; // ���� �ϳ��� �ٿ��ֱ�
			if (degree[i] == 0) // ���� �پ 0�̵ƴٸ� ���� Ǯ���ִ� ������ push ����
				pq.push(i);
		}
	}
	return 0;
}