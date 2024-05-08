#include<bits/stdc++.h>
using namespace std;

// 2024.05.08
// Written by JongTKim

// 푼 방법 : 자료구조(링크드 리스트, 스택)

string str;
char ch, ch2;
int num; // 명령어의 개수

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> str;

	// for (int i = 0; i < str.length(); i++) arr.push_back(str[i]);

	list<char> arr(str.begin(), str.end()); // 위처럼 반복문없이 Linkedlist를 초기화하는 방법

	//list<char>::iterator cur = arr.end();

	auto cur = arr.end(); // 위처럼 iterator로 받을필요없이 auto로 변수의 타입을 자동으로 추론

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
				// erase 함수는 iterator가 가리키는 부분의 원소 삭제 -> 그래서 cur--가 필요한것이다.
				// 삭제된 원소의 다음 원소를 반환한다
			}
		}
		else { // P인경우
			cin >> ch2;
			arr.insert(cur, ch2);
			// insert 함수는 iterator가 가리키는 부분 앞에 value값을 가지는 원소를 추가
		}
	}

	for (auto c : arr) cout << c;
	
	return 0;
}