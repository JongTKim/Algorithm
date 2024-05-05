#include <algorithm>
#include <iostream>
#include <list>
#include <math.h>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;

/*

바킹독 알고리즘
https://github.com/encrypted-def/basic-algo-lecture/blob/master/workbook.md
  */
int n;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
        vector<int> v;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            v.push_back(k);
        }
        int mx = v[0];
        int idx = 0;
        int ans = 0;
        int money = 0;
        int cnt = 0;
        while (idx + 1 < n) {
            int pre = idx;
            for (int i = idx + 1; i < n; i++) {
                if (mx < v[i]) {
                    mx = v[i];
                    idx = i;
                }
            }
            for (int i = pre; i < idx; i++) {
                cnt++;
                money += v[i];
            }
            ans += mx * cnt - money;
            if (idx + 1 < n) {
                mx = v[idx + 1];
                idx += 1;
            }
            money = 0;
            cnt = 0;
        }

        cout << ans << endl;
    }

    return 0;
}