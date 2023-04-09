#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void input();
void solve();

int n, m, k;
vector<int> v;

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
	cout << (int) (n * 0.78) << ' ' << (int) (n - (n * 0.2 * 0.22));
}

void solve() {
	
}