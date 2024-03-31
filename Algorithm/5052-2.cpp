#include<bits/stdc++.h>

using namespace std;

struct Trie {
	bool isEnd;
	Trie* node[10];
	Trie() {
		isEnd = false;
		for (int i = 0; i < 10; i++) {
			node[i] = nullptr;
		}
	}
};

// Trie* now = &trie 를 사용하는 이유는 now가 바뀌어도 trie가 변경되기를 원하기때문

void Insert(string phone, Trie& trie) {
	Trie* now = &trie;
	for (int i = 0; i < phone.length(); ++i) {
		if (now->node[phone[i] - '0'] == nullptr) {
			now->node[phone[i] - '0'] = new Trie();
		}
		now = now->node[phone[i] - '0'];
		if (i == phone.length() - 1) now->isEnd = true;
	}
}

bool find(string phone, Trie& trie) {
	Trie* now = &trie;
	for (int i = 0; i < phone.length(); ++i) {
		if (now->node[phone[i] - '0'] != nullptr) {
			now = now->node[phone[i] - '0'];
			if (now->isEnd)
				return true;
		}
		else
			return false;
	}
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		bool flag = false;
		string str;
		vector<string> vec;
		Trie trie;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> str;
			vec.push_back(str);
		}
		// 입력

		sort(vec.begin(), vec.end());

		// 정렬

		for (string str : vec) {
			if (find(str, trie)) {
				flag = true;
				break;
			}
			Insert(str, trie);
		}

		if (flag) cout << "NO" << "\n";
		else cout << "YES" << "\n";



	}
	return 0;
}