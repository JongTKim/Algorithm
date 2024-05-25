#include<bits/stdc++.h>
using namespace std;

string str;
int ch[10];
int num = 1;
int cnt;
int scnt;

int main() {
	cin >> str;

	int len = str.length();

	while (cnt != len) {
		string st = to_string(num);
		for (char c : st) 
			if (str[cnt] == c) cnt++;
		num++;
	}

	cout << num-1 << "\n";


	return 0;
}