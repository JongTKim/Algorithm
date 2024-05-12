#include<bits/stdc++.h>
using namespace std;

// 2024.05.12
// Written by JongTKim

// 푼 방법 : 브루트포스, 스택

int N;
int arr[1001];
int fsum, num1, num2;


void solve1() {
	int sstart = 1001, eend=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num1 >> num2;
		sstart = min(sstart, num1);
		eend = max(eend, num1);
		arr[num1] = num2;
	}
	for (int i = sstart; i <= eend; i++) { // 하나하나 다 돌면서
		int lmax = 0, rmax = 0;
		for (int j = sstart; j < i; j++) { // left
			lmax = max(lmax, arr[j]);
		}
		for (int j = i + 1; j <= eend; j++) { // right
			rmax = max(rmax, arr[j]);
		}

		// 여기까지오면 자신 왼,오의 최댓값을 찾은 상태, 이제 자기 값이랑 비교하자.

		int mine = arr[i];

		if (mine < lmax && mine < rmax) {
			fsum += min(lmax, rmax);
		}
		else {
			fsum += mine;
		}
	}
}

void solve2() {
	int maxpos=0, maxh = 0, lmax = 0, rmax = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num1 >> num2;
		arr[num1] = num2;
		if (maxh < num2) { // 최대높이 찾기
			maxh = num2, maxpos = num1;
		}
	}
	// 입력완료
	for (int i = 0; i < maxpos; i++) { // 좌측에서 -> 이방향 전진
		lmax = max(lmax, arr[i]);
		fsum += lmax; // 현재까지중 가장 높은 높이로 추가
	}
	for (int i = 1000; i > maxpos; i--) { // 우측에서 <- 이방향 전진
		rmax = max(rmax, arr[i]);
		fsum += rmax; // 현재까지중 가장 높은 높이로 추가
	}

	fsum += maxh; // 마지막으로 최대 높이 추가
}

void solve3() {
	stack<pair<int, int>> st;
	vector<pair<int, int>> vec;
	int maxh = 0, maxloc = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num1 >> num2;
		if (maxh < num2) maxh = num2, maxloc = num1; // 최대높이 찾기 (maxloc까지 꼭기록해야됨)
		vec.push_back({ num1,num2 }); // {위치, 높이}
	}

	sort(vec.begin(), vec.end()); // num1이 우선으로 sort되었을것.

	st.push({ vec[0].first, vec[0].second });

	for (int i = 1; i < vec.size(); i++) {
		if (vec[i].second == maxh && vec[i].first == maxloc) {
			pair<int, int> p = st.top();
			st.pop();
			for (int j = 0; j < vec[i].first - p.first; j++) fsum += p.second;
			// 지금까지 스택에 있는 모든 정보들 다 털고 끝내기
			break;
		}
		if (vec[i].second > st.top().second) { // 더 큰게 들어왔으면 
			pair<int, int> p = st.top();
			st.pop();
			for (int j = 0; j < vec[i].first - p.first; j++) {
				fsum += p.second;
			}
			st.push({ vec[i].first, vec[i].second });
		}
	}

	st.push({ vec[N - 1].first, vec[N - 1].second });

	for (int i = vec.size() - 2; i >= 0; i--) {
		if (vec[i].second == maxh && vec[i].first == maxloc) {
			pair<int, int> p = st.top();
			st.pop();
			for (int j = 0; j < p.first - vec[i].first; j++) fsum += p.second;
			// 지금까지 스택에 있는 모든 정보들 다 털고 끝내기
			break;
		}
		if (vec[i].second > st.top().second) { // 더 큰게 들어왔으면 
			pair<int, int> p = st.top();
			st.pop();
			for (int j = 0; j < p.first - vec[i].first; j++) {
				fsum += p.second;
			}
			st.push({ vec[i].first, vec[i].second });
		}
	}

	fsum += maxh;
}

int main(){

	/*
	for (int i = 1; i < 999; i++) {
		cout << i << " " << (rand() % 1000) << "\n";
	}
	*/
	clock_t start = clock();

	// 1번풀이의 시간복잡도는 O(N^2)
	//solve1();

	// 2번풀이의 시간복잡도는 O(N)
	//solve2();

	// 3번풀이는 스택
	solve3();
	

	clock_t end = clock();
	double result = (double)(end - start);
	cout << "수행시간 : " << result << "ms" << "\n";

	cout << fsum << "\n";

	return 0;
}