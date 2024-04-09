#include<bits/stdc++.h>
using namespace std;

// 2024.04.09
// Writen by JongTKim

// Ǭ ��� : ��������

int arr[32005]; // ������ ��Ÿ��
vector<int> vec[32005];

int main() {
	
	int N, M;
	int a, b;

	cin >> N >> M;


	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		vec[a].push_back(b); // ���� �ٿ��ֱ� ����
		arr[b]++;
	}


	queue<int> q;

	for (int i = 1; i <= N; i++) { // �ٷ� ����� �ִ¾ֵ�
		if (!arr[i]) q.push(i);
	}

	while (!q.empty()) {

		int front = q.front();
		q.pop();
		for (int i : vec[front]) {
			arr[i]--;
			if (!arr[i]) q.push(i);
		}
		
		cout << front << " ";
	}


	return 0;
}