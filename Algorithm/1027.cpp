#include<bits/stdc++.h>
using namespace std;

// 2024.04.08
// Writen by JongTKim

// Ǭ ��� : ����Ž��, ����
int height[55];
int b[55];

int main() {
	// �ؿ����� ������ ���. 
	// �����غ��� �¿츦 ���� ������ʿ䰡����.
	// ���� �ǹ����� ������ �����ǹ��� ���̴°�, ������ �ǹ������� ���� �ǹ��� �� �� �ִٴ� �Ҹ���
	// ��� �����ʸ� Ž���ϸ� �ȴ�. (�����ʼ�)
	int N, num, fcnt = 0, j;
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> height[i];

	for (int i = 1; i <= N; i++) {
		double mmin = -1000000000, gr;
		for (int j = i + 1; j <= N; j++) {
			gr = (double)(height[i] - height[j]) / (i - j); // ���� ���ϱ�
			if (gr > mmin) mmin = gr, b[i]++, b[j]++;
		}
	}
	cout << *max_element(b, b + N + 1) << "\n";

	return 0;
}

/*#include<bits/stdc++.h>
using namespace std;

int height[55];
int b[55];

int main() {
	int N, num, fcnt = 0, j;
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> height[i];

	for (int i = 1; i <= N; i++) {
		j = i;
		double mmin = -1000000000, mmax = 1000000000, gr;
		int cnt = 0;
		while (j - 1 >= 1) { // �������� �� �� �ִ��� Ȯ��
			j--;
			gr = (double)(height[i] - height[j]) / (i - j); // ���� ���ϱ�
			if (gr < mmax) mmax = gr, cnt++;
		}

		j = i;
		while (j + 1 <= N) { // ���������� �� �� �ִ��� Ȯ��
			j++;
			gr = (double)(height[i] - height[j]) / (i - j); // ���� ���ϱ�
			if (gr > mmin) mmin = gr, cnt++;
		}
		fcnt = max(fcnt, cnt);
	}
	cout << fcnt << "\n";
	//cout << *max_element(b,b+N) << "\n";

	return 0;
}*/