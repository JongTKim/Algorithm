#include<bits/stdc++.h>
using namespace std;

// 2024.04.23
// Writen by JongTKim

// Ǭ ��� : ���Ͽ� ���ε�, �и� ����

int people[51];
int partynum[51];
int arr[51][51];
int rnum, num, cnt, N, M;

int get_parent(int x) {
	if (people[x] == x) return x;
	return people[x] = get_parent(people[x]);
}

void union_parent(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a < b) people[b] = a;
	else if (a > b) people[a] = b;
}

int main() {
	// 1. �����, ��Ƽ�� �ޱ�
	cin >> N >> M;


	// 2. Union-find �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		people[i] = i;
	}

	// 3. ���� �ƴ� ����� ��ȣ�� �����鼭, �� ��ȣ�� �θ� ��带 0������ ����
	cin >> rnum;
	for (int i = 0; i < rnum; i++) {
		cin >> num;
		people[num] = 0;
	}

	// 4. ��Ƽ�� �»���� 2���̻��̸� ���� Union�� ���ش�
	for (int i = 0; i < M; i++) {
		cin >> partynum[i];
		cin >> arr[i][0]; // ù��° ��� ���
		for (int j= 1; j < partynum[i]; j++) {
			cin >> arr[i][j];
			union_parent(arr[i][0], arr[i][j]); // ������ �»����� �̾��ֱ�
		}
	}

	// 5. ������� ���� �θ� 0���� ���� �� �ƴ� ����̹Ƿ� �������� �Ҽ�����
	for (int i = 0; i < M; i++) {
		bool flag = false;
		for (int j = 0; j < partynum[i]; j++) {
			if (get_parent(people[arr[i][j]]) == 0) {
				flag = true;
				break;
			}
		}
		if (!flag) cnt++; // flag�� 0�̸� cnt ������Ű��
	}

	cout << cnt << "\n";

	return 0;
}



/* �������ε� �����ϴ�

#include<bits/stdc++.h>
using namespace std;

bool dp[51];
int arr[51][51];
int pnum[51];
int flag;
int cnt;

int main() {
	int N, M, rnum, num;

	cin >> N >> M;
	
	cin >> rnum;
	for (int i = 0; i < rnum; i++) {
		cin >> num;
		dp[num] = 1;
	}


	for (int i = 0; i < M; i++) {
		cin >> pnum[i];
		for (int j = 0; j < pnum[i]; j++) {
			cin >> arr[i][j];
		}
	}

	for (int k = 0; k < M; k++) {
		for (int i = 0; i < M; i++) {
			flag = 0;
			for (int j = 0; j < N; j++) {
				if (dp[arr[i][j]]) flag = 1; // ���� �̹� �ƴ� ����� ���ִٸ�
			}
			// flag=1�̸� �� ��Ƽ�� �ƴ»���� �ִ°Ŵϱ� �� ����� �������״� ���� ��ħ(�ƴ»�� �������� �־����)
			if (flag) {
				for (int j = 0; j < pnum[i]; j++) dp[arr[i][j]] = 1;
			}
		}
	}

	// ���⿡ ������ �Է��� ����, �ƴ»�� ���ܵ� ���� �������
	for (int i = 0; i < M; i++) {
		flag = 0;
		for (int j = 0; j < N; j++) {
			if (dp[arr[i][j]]) {
				flag = 1;
				break;
			}
			// ���� ������ �ƴ� ��� �ƹ������°� �����ĵ���
		}
		if (!flag) cnt++;
	}

	cout << cnt << "\n";
	return 0;
}
*/