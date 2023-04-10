// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void input();
void solve();

int n, d, ans;
priority_queue<int, vector<int>, greater<int>> points;
priority_queue<int, vector<int>, greater<int>> starts;
vector<pair<int, int>> routes;

bool cmp (pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    input();
    solve();
    
    return 0;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, l;
        cin >> s >> l;
        if (s > l)
            swap(s, l);
        routes.push_back({ s, l });
        points.push(l);
    }
    cin >> d;
}

void solve() {
    sort(routes.begin(), routes.end(), cmp);
    int start, last = 0;
    int idx = 0;
    while (!points.empty()) {
        last = points.top();
        start = last - d;
        int s = routes[idx].first;
        if (start <= s)
            starts.push(s);
        idx++; 
        while (!starts.empty()) {
            if (start <= starts.top())
                break;
            starts.pop();
        }
        ans = max(ans, (int) starts.size());
        points.pop();
    }
    cout << ans;
}