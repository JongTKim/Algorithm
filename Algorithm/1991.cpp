#include<bits/stdc++.h>
using namespace std;

struct node {
	char left;
	char right;
};

char ch, l, r;
vector<node> vec(100);

void preOrder(char node) { // 전위 순회
	// root - left - right
	if (node == '.') return;

	printf("%c", node);
	preOrder(vec[node].left);
	preOrder(vec[node].right);
}

void inOrder(char node) { // 전위 순회
	// root - left - right
	if (node == '.') return;

	inOrder(vec[node].left);
	printf("%c", node);
	inOrder(vec[node].right);
}

void postOrder(char node) { // 전위 순회
	// root - left - right
	if (node == '.') return;

	postOrder(vec[node].left);
	postOrder(vec[node].right);
	printf("%c", node);
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ch >> l >> r;
		vec[ch].left = l;
		vec[ch].right = r;
	}

	preOrder('A'); cout << "\n";
	inOrder('A'); cout << "\n";
	postOrder('A'); cout << "\n";


	return 0;
}