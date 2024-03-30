#include<bits/stdc++.h>
using namespace std;


// 2024.03.30
// Writen by JongTKim

int main() {

	
	// 푼방법
	// 처음에는 완전 탐색을 생각, 하지만 1백만 x 128 x 여러개의 테스트 케이스 => 시간복잡도 1억초과
	// 다른 방식을 찾다가 투포인터를 생각.

	while (true) {
		int m;
		string str;
		int ch[128] = { 0 }; // m개중에 포함된 문자의 수, 문자를 숫자 배열로 저장하게된다 A는 65에 저장되게됨
		int cnt = 0; // 현재 몇개의 "다른" 문자를 받았는지
		int mf = 0; // 가장 긴 문자열의 길이

		cin >> m;
		if (m == 0) break; // 종료조건

		cin.ignore(); // cin을 사용했을때 개행문자가 남아있으므로, 입력버퍼 지우기
		getline(cin, str); // 입력받는부분. getline을 통해서 공백까지 입력받는다

		int left = 0, right = 0;

		while (cnt < m && right < str.length()) { 
			// 아직 다른 문자 m개가 안찬상태일때 && right가 문자열의 길이를 넘으면안됨
			// 예를들어, m이 3이고 abcaaaaaaa일때 뒷조건이 없으면 "Out of range" 날수있음

			if (!ch[(int)(str[right])]) // 새로 들어오는 문자일때만, 다른 문자 개수 추가
				cnt++;

			ch[(int)(str[right])]++; 
			right++;
			// 새로 들어오는 문자가 아니면 cnt는 올리지않음 
			// 예를들어 abc가 있고, a가 들어올때 abca에서 서로 다른 문자의 개수는 3이니깐 cnt를 올릴필요가 없음
			// 다만, ch[]값은 추가해줘서 abca에서 a가 빠져도 아직 a가 들어오면 받아줄수있다는걸 표시해줘야함
		}
		
		while (left <= right && right < str.length()) {
			if (!ch[(int)(str[right])]) { // 만약 현재 넣으려는 문자가 새로운 문자일때 (abc가 있는데 다음으로 d가 들어올때)

				// 새로운게 들어갈 공간을 마련해줘야됨(cnt를 하나 비운다 생각하면됨)
				while (cnt >= m) { 
					ch[(int(str[left]))]--;
					if (ch[(int(str[left]))] == 0) { 
						// 만약, 그 문자를 제외해서 그 문자가 한번도 안들어가면 cnt 줄여주기
						// 이유는 m이 3이고, abca에서 d를 받을때 맨앞 a만 삭제해서는 ch[a]=2에서 1이 된거이므로, b까지 삭제 해줘야하기 때문
						cnt--;
					}
					left++;
				}
				ch[(int)(str[right])]++; 
				right++; cnt++; // 지금은 없는 문자가 들어온거니 무조건 cnt++ 해줘야함
			}

			else { // 지금 m개 문자안에 있는 문자가 들어올때 (abc가 있는데 다음으로 a가 들어올때)
				ch[(int)(str[right])]++;
				right++;
				mf = max(mf, right - left); // 현재 문자열의 길이를 계속 갱신해나감
			}
		}
		mf = max(mf, right - left); // m이 3이고 abcaaaaaa같은 밑에 while문을 안탈경우를 고려

		cout << mf << "\n";
	}

	return 0;
}