#include<bits/stdc++.h>
using namespace std;

// 2024.04.23
// Writen by JongTKim

// 푼 방법 : 유니온 파인드, 분리 집합

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
	// 1. 사람수, 파티수 받기
	cin >> N >> M;


	// 2. Union-find 초기화
	for (int i = 1; i <= N; i++) {
		people[i] = i;
	}

	// 3. 진실 아는 사람의 번호를 받으면서, 그 번호는 부모 노드를 0번으로 설정
	cin >> rnum;
	for (int i = 0; i < rnum; i++) {
		cin >> num;
		people[num] = 0;
	}

	// 4. 파티에 온사람이 2명이상이면 서로 Union을 해준다
	for (int i = 0; i < M; i++) {
		cin >> partynum[i];
		cin >> arr[i][0]; // 첫번째 사람 잡고
		for (int j= 1; j < partynum[i]; j++) {
			cin >> arr[i][j];
			union_parent(arr[i][0], arr[i][j]); // 다음에 온사람들과 이어주기
		}
	}

	// 5. 여기까지 오면 부모가 0번인 노드는 다 아는 사람이므로 거짓말을 할수없다
	for (int i = 0; i < M; i++) {
		bool flag = false;
		for (int j = 0; j < partynum[i]; j++) {
			if (get_parent(people[arr[i][j]]) == 0) {
				flag = true;
				break;
			}
		}
		if (!flag) cnt++; // flag가 0이면 cnt 증가시키기
	}

	cout << cnt << "\n";

	return 0;
}



/* 구현으로도 가능하다

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
				if (dp[arr[i][j]]) flag = 1; // 만약 이미 아는 사람이 들어가있다면
			}
			// flag=1이면 그 파티에 아는사람이 있는거니깐 그 사람들 전부한테는 구라를 못침(아는사람 집단으로 넣어야함)
			if (flag) {
				for (int j = 0; j < pnum[i]; j++) dp[arr[i][j]] = 1;
			}
		}
	}

	// 여기에 나오면 입력은 물론, 아는사람 집단도 전부 만들어짐
	for (int i = 0; i < M; i++) {
		flag = 0;
		for (int j = 0; j < N; j++) {
			if (dp[arr[i][j]]) {
				flag = 1;
				break;
			}
			// 여기 왔으면 아는 사람 아무도없는거 구라쳐도됨
		}
		if (!flag) cnt++;
	}

	cout << cnt << "\n";
	return 0;
}
*/