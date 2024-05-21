#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// 2024.05.21
// Written by JongTKim

// 푼 방법 : 자료구조, 해시셋

int N, M;
unordered_set<string> st;
string str;

void fastio() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
}
void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> str;
        st.insert(str);
    }
}
void solve1() {
    for (int i = 0; i < M; i++) {
        cin >> str;
        size_t start = 0;
        size_t end = str.find(',');
        while (end != string::npos) {
            string token = str.substr(start, end - start);
            st.erase(token);
            start = end + 1;
            end = str.find(',', start);
        }
        // 마지막 토큰 처리
        st.erase(str.substr(start));
        cout << st.size() << "\n";
    }
}
void solve2() {
    for (int i = 0; i < M; i++) {
        cin >> str;
        istringstream ss(str);
        string token;
        while (getline(ss, token, ',')) st.erase(token);
        cout << st.size() << "\n";
    }
}
int main() {
    fastio();
    input();
    solve2();
    return 0;
}
