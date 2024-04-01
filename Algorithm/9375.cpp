#include<bits/stdc++.h>
using namespace std;

// 2024.04.01
// Writen by JongTKim


// 푼 방법 : 조합론
// 모자가 2가지, 상의가 2가지있으면 
// (모자안씀, 모자1,모자2) * (상의안씀, 상의1, 상의2) = (n+1) * (m+1) = 9개가 나오는데 
// 그 중(모자안씀, 상의안씀)의 알몸의 경우 문제에서 제외한다 했으니 하나를 빼주면 된다
int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		int n, max=1;
		string name, cat; 
		map<string, int> mt;

		cin >> n;

		while (n--) {
			cin >> name >> cat;
			mt[cat]++;
		}

		for (pair<string, int> pr : mt) {
			max *= (pr.second+1);
		}

		cout << max - 1 << "\n";
	}
	return 0;
}