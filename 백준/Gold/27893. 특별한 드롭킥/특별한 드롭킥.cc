#include <iostream>
#include <queue>

using namespace std;

char path[200001];
priority_queue<int, vector<int>, greater<int>> pq;
int ans = 0;
int obstacle = 0;

int main() {
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> path[i];
        if (path[i] == 'X')
            obstacle++;
        if (cnt && path[i] == 'X') {
            pq.push(i - cnt);
            cnt = 0;
        }
        else if (path[i - 1] == 'X' && path[i] == '.')
            cnt = i;
    }

    bool x = false;
    for (int i = 1; i <= n; i++) {
        if (!x)
            path[i] == 'X' ? x = true : ans++;
        else if (path[i] == '.') {
            ans += 3;
            x = false;
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