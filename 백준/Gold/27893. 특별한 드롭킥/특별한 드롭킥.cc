#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int ans = 0;
int obstacle = 0;

/*
* 원래 코드
* 1. 장애물 사이의 간격을 구함 -> pair pq에 해당 위치와 같이 저장
* 2. 복도를 돌면서 장애물을 설치함
* 3. 복도를 걸어감
* 4. 나머지 처리
* 
* 수정사항
* 1. 간격만 알면 됨 -> 일반 pq
* 2. 장애물을 직접 놓을 필요 없음 -> 그냥 사칙연산으로 처리 가능
* 3. 간격을 구하는 반복문과 복도를 걸어가는 반복문을 합침
*/
int main() {
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    char c;
    bool x = false;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        if (c == 'X') {
            obstacle++;
            x = true;
            if (cnt) {
                pq.push(i - cnt);
                cnt = 0;
            }
        }
        else {
            if (x) {
                cnt = i;
                ans += 3;
                x = false;
            }
            else
                ans++;
        }
    }
    if (x)
        ans += 2;

    while (!pq.empty()) {
        cnt = pq.top();
        if (cnt <= m) {
            m -= cnt;
            ans -= (cnt + 2);
        }
        else
            break;
        pq.pop();
    }

    ans -= (!obstacle ? (m >= 3 ? m - 2 : 0) : m);

    cout << ans;
    return 0;
}