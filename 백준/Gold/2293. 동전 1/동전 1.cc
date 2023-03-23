#include <iostream>
#include <algorithm>

using namespace std;

void input();
void solve();

int n, k;
int coin[101];
int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}

void input() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> coin[i];
}

void solve() {
	sort(coin + 1, coin + 1 + n);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			int c = coin[i];
			if (c <= j)
				dp[j] += dp[j - c];
		}
	}
	cout << dp[k];
}