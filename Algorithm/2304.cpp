#include<bits/stdc++.h>
using namespace std;

// 2024.05.12
// Written by JongTKim

// Ǭ ��� : ���Ʈ����, ����

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
	for (int i = sstart; i <= eend; i++) { // �ϳ��ϳ� �� ���鼭
		int lmax = 0, rmax = 0;
		for (int j = sstart; j < i; j++) { // left
			lmax = max(lmax, arr[j]);
		}
		for (int j = i + 1; j <= eend; j++) { // right
			rmax = max(rmax, arr[j]);
		}

		// ����������� �ڽ� ��,���� �ִ��� ã�� ����, ���� �ڱ� ���̶� ������.

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
		if (maxh < num2) { // �ִ���� ã��
			maxh = num2, maxpos = num1;
		}
	}
	// �Է¿Ϸ�
	for (int i = 0; i < maxpos; i++) { // �������� -> �̹��� ����
		lmax = max(lmax, arr[i]);
		fsum += lmax; // ��������� ���� ���� ���̷� �߰�
	}
	for (int i = 1000; i > maxpos; i--) { // �������� <- �̹��� ����
		rmax = max(rmax, arr[i]);
		fsum += rmax; // ��������� ���� ���� ���̷� �߰�
	}

	fsum += maxh; // ���������� �ִ� ���� �߰�
}

void solve3() {
	stack<pair<int, int>> st;
	vector<pair<int, int>> vec;
	int maxh = 0, maxloc = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num1 >> num2;
		if (maxh < num2) maxh = num2, maxloc = num1; // �ִ���� ã�� (maxloc���� ������ؾߵ�)
		vec.push_back({ num1,num2 }); // {��ġ, ����}
	}

	sort(vec.begin(), vec.end()); // num1�� �켱���� sort�Ǿ�����.

	st.push({ vec[0].first, vec[0].second });

	for (int i = 1; i < vec.size(); i++) {
		if (vec[i].second == maxh && vec[i].first == maxloc) {
			pair<int, int> p = st.top();
			st.pop();
			for (int j = 0; j < vec[i].first - p.first; j++) fsum += p.second;
			// ���ݱ��� ���ÿ� �ִ� ��� ������ �� �а� ������
			break;
		}
		if (vec[i].second > st.top().second) { // �� ū�� �������� 
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
			// ���ݱ��� ���ÿ� �ִ� ��� ������ �� �а� ������
			break;
		}
		if (vec[i].second > st.top().second) { // �� ū�� �������� 
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

	// 1��Ǯ���� �ð����⵵�� O(N^2)
	//solve1();

	// 2��Ǯ���� �ð����⵵�� O(N)
	//solve2();

	// 3��Ǯ�̴� ����
	solve3();
	

	clock_t end = clock();
	double result = (double)(end - start);
	cout << "����ð� : " << result << "ms" << "\n";

	cout << fsum << "\n";

	return 0;
}