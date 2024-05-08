#include<bits/stdc++.h>
using namespace std;

// 2024.05.08
// Written by JongTKim

// Ǭ ��� : �ڷᱸ��(��ũ�� ����Ʈ, ����)

string str;
char ch, ch2;
int num; // ��ɾ��� ����

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> str;

	// for (int i = 0; i < str.length(); i++) arr.push_back(str[i]);

	list<char> arr(str.begin(), str.end()); // ��ó�� �ݺ������� Linkedlist�� �ʱ�ȭ�ϴ� ���

	//list<char>::iterator cur = arr.end();

	auto cur = arr.end(); // ��ó�� iterator�� �����ʿ���� auto�� ������ Ÿ���� �ڵ����� �߷�

	cin >> num;
	while (num--) {
		cin >> ch;
		if (ch == 'L') {
			if(cur != arr.begin())
				cur--;
		}
		else if (ch == 'D') {
			if (cur != arr.end())
				cur++;

		}
		else if (ch == 'B') {
			if (cur != arr.begin()) {
				cur--;
				cur = arr.erase(cur); 
				// erase �Լ��� iterator�� ����Ű�� �κ��� ���� ���� -> �׷��� cur--�� �ʿ��Ѱ��̴�.
				// ������ ������ ���� ���Ҹ� ��ȯ�Ѵ�
			}
		}
		else { // P�ΰ��
			cin >> ch2;
			arr.insert(cur, ch2);
			// insert �Լ��� iterator�� ����Ű�� �κ� �տ� value���� ������ ���Ҹ� �߰�
		}
	}

	for (auto c : arr) cout << c;
	
	return 0;
}