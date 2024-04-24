#include<bits/stdc++.h>
using namespace std;

// 2024.04.24
// Written by JongTKim

// Ǭ ��� : DP(Knapsack)

int C, N;
int dp[1101]; // ����) dp[1] = 2, 1���� ���� �þ�������� �ּҺ���� 2
struct city { int cost, customer; };
city ct[21];

bool cmp(city A, city B) { // ����ü city ������ ����
	if (A.customer == B.customer) return A.cost < B.cost;
	return A.customer < B.customer;
}

void input() {
	cin >> C >> N;
	for (int i = 0; i < N; i++)
		cin >> ct[i].cost >> ct[i].customer;
}

int main() {

	// 1. �Է�
	input();

	// 2. ���� ���� ������������ ����
	sort(ct, ct + N, cmp);

	// 3. min���� ���ؾ��ϹǷ� dp�� �ʱ�ȭ
	// Q1) �� 10��? -> 1000���� �÷����ϰ�, 1��ø��µ� 100���� ���̴� ���ùۿ� ��������������
	// A1) �ִ� 10������ ����Ѵ�. ���� 99999���� �����ÿ��� ������ �߻��Ѵ�.
	// Q2) �� 1101? -> 1000�̻󿡼��� �ּڰ��� ���ü��ִ�.
	// A2) ���� 1000�� �ø����µ�, (1��)1��,500�� / (2��)99��,1���� ������,
	// 1000���� �س��´ٸ� 99 * 11 = 1089���� ��� 11���� ���°��� ���õ����ʰ�
	// 99 *10 + 1*10�� ���õǾ�  5010���� �����ϰԵȴ�. �װ� �����ϱ� ���� �˳��ϰ� 1101�� ����
	fill(dp, dp + 1101, 100000);

	// 4. dp �ʱⰪ
	dp[0] = 0;

	// 5. dp ����
	for (int i = 0; i < N; i++) {
		for (int j = ct[i].customer; j <= 1100; j++)
			dp[j] = min(dp[j], dp[j - ct[i].customer] + ct[i].cost); // ������ dp���� i ���ø� ���ؼ� �� ����� ���Ѱ��� �������� ���ϰԵ�
	}

	// 6. 3������ �����Ѱ�ó�� C�̻󿡼��� �ּڰ��� ���ü� �����Ƿ� Ž���� �ʿ�
	int maxi = 100000;
	for (int i = C; i <= 1100; i++) maxi = min(dp[i], maxi);
	cout << maxi << "\n";

	return 0;
}