#include<bits/stdc++.h>
using namespace std;

// 2024.04.24
// Written by JongTKim

// 푼 방법 : DP(Knapsack)

int C, N;
int dp[1101]; // 예시) dp[1] = 2, 1명의 고객을 늘어나게했을때 최소비용은 2
struct city { int cost, customer; };
city ct[21];

bool cmp(city A, city B) { // 구조체 city 정렬을 위함
	if (A.customer == B.customer) return A.cost < B.cost;
	return A.customer < B.customer;
}

void input() {
	cin >> C >> N;
	for (int i = 0; i < N; i++)
		cin >> ct[i].cost >> ct[i].customer;
}

int main() {

	// 1. 입력
	input();

	// 2. 고객의 수를 오름차순으로 정렬
	sort(ct, ct + N, cmp);

	// 3. min값을 구해야하므로 dp값 초기화
	// Q1) 왜 10만? -> 1000명을 늘려야하고, 1명늘리는데 100원이 들이는 도시밖에 존재하지않을때
	// A1) 최대 10만원을 써야한다. 만약 99999으로 설정시에는 오류가 발생한다.
	// Q2) 왜 1101? -> 1000이상에서도 최솟값이 나올수있다.
	// A2) 만약 1000을 늘리려는데, (1번)1명,500원 / (2명)99명,1원이 있을때,
	// 1000으로 해놓는다면 99 * 11 = 1089명을 얻고 11원만 내는것이 선택되지않고
	// 99 *10 + 1*10이 선택되어  5010원을 내야하게된다. 그걸 방지하기 위해 넉넉하게 1101로 설정
	fill(dp, dp + 1101, 100000);

	// 4. dp 초기값
	dp[0] = 0;

	// 5. dp 실행
	for (int i = 0; i < N; i++) {
		for (int j = ct[i].customer; j <= 1100; j++)
			dp[j] = min(dp[j], dp[j - ct[i].customer] + ct[i].cost); // 현재의 dp값과 i 도시를 택해서 그 비용을 더한값중 작은값을 택하게됨
	}

	// 6. 3번에서 설명한것처럼 C이상에서도 최솟값이 나올수 있으므로 탐색이 필요
	int maxi = 100000;
	for (int i = C; i <= 1100; i++) maxi = min(dp[i], maxi);
	cout << maxi << "\n";

	return 0;
}