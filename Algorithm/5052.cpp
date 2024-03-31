#include<bits/stdc++.h>

using namespace std;


int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		bool flag = false;
		string str;
		vector<string> vec;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> str;
			vec.push_back(str);
		}
		// 입력

		sort(vec.begin(), vec.end());

		// 정렬
		
		for (int i = 1; i < vec.size(); i++) {
			if(vec[i].substr(0,vec[i-1].length()) == vec[i-1]){
				flag = true;
				break;
			}
			else {
				continue;
			}
		}

		if (flag == true) cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}
	return 0;
}