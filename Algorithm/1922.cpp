#include<bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> p; // {가중치, {노드1, 노드2}}가 들어갈 자료구조
vector<p> vec;
int N, M;
int a, b, c;
int parent[1001];
int fsum;
int flag;

int find_root(int x) {
	if (parent[x] == x) return x; // 자신이 부모야? => 바로 리턴
	return parent[x] = find_root(parent[x]); // 자신이 부모가 아니야? => root node(부모)를 찾기위해 재귀
}

void union_root(int a, int b) {
	a = find_root(a);
	b = find_root(b);
	if (a != b) parent[b] = a; // 한 노드의 루트를 다른 노드의 자식으로 이어주기
}

void kruskal() {
	for (p pr : vec) { // 0. 크루스칼 알고리즘은 가중치(비용)이 낮은것부터 시작한다. (기본원리)

		// 1. pr의 두 node의 부모를 찾아준다 => 만약, 같다면 사이클이 발생하므로 continue
		int node1 = pr.second.first;
		int node2 = pr.second.second;
		if (find_root(node1) == find_root(node2)) continue;

		// 2. 두 노드의 root가 다르다면 union으로 root를 연결해준다(연결후에는 root가 같아질것이기 때문)
		union_root(node1, node2);

		// 3. 그때의 비용 fsum에 추가하고 간선수를 1 증가시킨다.
		fsum += pr.first; flag++;

		// 4. 만약 간선수가 노드개수 -1이면 모든 노드가 연결된것이므로 끝내기
		if (flag == N - 1) return;
	}
}

int main() {
	cin >> N >> M; // 노드의 개수가 N개일때 N-1개의 간선을 완성시켜야 모든 컴퓨터를 연결할수있다.

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		vec.push_back({ c,{a,b} });
	}

	sort(vec.begin(), vec.end()); // 크루스칼을 위해 가중치로 정렬

	for (int i = 1; i <= N;  i++) parent[i] = i; // Union-Find를 위한 Setting

	kruskal();

	cout << fsum << "\n";
	return 0;
}