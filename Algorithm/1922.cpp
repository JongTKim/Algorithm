#include<bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> p; // {����ġ, {���1, ���2}}�� �� �ڷᱸ��
vector<p> vec;
int N, M;
int a, b, c;
int parent[1001];
int fsum;
int flag;

int find_root(int x) {
	if (parent[x] == x) return x; // �ڽ��� �θ��? => �ٷ� ����
	return parent[x] = find_root(parent[x]); // �ڽ��� �θ� �ƴϾ�? => root node(�θ�)�� ã������ ���
}

void union_root(int a, int b) {
	a = find_root(a);
	b = find_root(b);
	if (a != b) parent[b] = a; // �� ����� ��Ʈ�� �ٸ� ����� �ڽ����� �̾��ֱ�
}

void kruskal() {
	for (p pr : vec) { // 0. ũ�罺Į �˰����� ����ġ(���)�� �����ͺ��� �����Ѵ�. (�⺻����)

		// 1. pr�� �� node�� �θ� ã���ش� => ����, ���ٸ� ����Ŭ�� �߻��ϹǷ� continue
		int node1 = pr.second.first;
		int node2 = pr.second.second;
		if (find_root(node1) == find_root(node2)) continue;

		// 2. �� ����� root�� �ٸ��ٸ� union���� root�� �������ش�(�����Ŀ��� root�� ���������̱� ����)
		union_root(node1, node2);

		// 3. �׶��� ��� fsum�� �߰��ϰ� �������� 1 ������Ų��.
		fsum += pr.first; flag++;

		// 4. ���� �������� ��尳�� -1�̸� ��� ��尡 ����Ȱ��̹Ƿ� ������
		if (flag == N - 1) return;
	}
}

int main() {
	cin >> N >> M; // ����� ������ N���϶� N-1���� ������ �ϼ����Ѿ� ��� ��ǻ�͸� �����Ҽ��ִ�.

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		vec.push_back({ c,{a,b} });
	}

	sort(vec.begin(), vec.end()); // ũ�罺Į�� ���� ����ġ�� ����

	for (int i = 1; i <= N;  i++) parent[i] = i; // Union-Find�� ���� Setting

	kruskal();

	cout << fsum << "\n";
	return 0;
}