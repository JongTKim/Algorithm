#include<bits/stdc++.h>
using namespace std;

string str;
int ro, box, target;

int main() {
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '@') ro = i+1;
		if (str[i] == '#') box = i+1;
		if (str[i] == '!') target = i+1;
	}

	if ((ro < box && box < target) || (ro > box && box > target)) {
		if (ro < box && box < target) cout << (box - ro - 1) + (target - box) << "\n";
		else cout << (ro - box - 1) + (box - target) << "\n";
	}
	else {
		cout << -1 << "\n";
	}
	return 0;
}