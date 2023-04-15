#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void input();
void solve();

int n, m, k;
int cnt[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}

void input() {
	int ans = 1;
	int n;
	cin >> n;
	while (n--) {
		int t;
		cin >> t;
		ans += t;
		ans--;
	}
	cout << ans;
}

void solve() {
	
}