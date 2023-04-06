#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void input();
void solve();

int n, dice;
int board[1000001];
vector<int> one;

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
	for (int i = 0; i <= n; i++) {
		cin >> board[i];
		if (board[i] == 1)
			one.push_back(i);
	}
	cin >> dice;
}

void solve() {
	int cur, next;
	bool yes = false;
	if (one.size() == 0) {
		for (int i = 0; i <= n; i++) {
			if (board[i] >= 3) {
				cur = i;
				next = i + dice;
				if (next <= n && board[next] >= 2) {
					yes = true;
					break;
				}
			}
		}
	}
	else if (one.size() == 1) {
		cur = one[0];
		next = cur + dice;
		if (next <= n && board[next] >= 2)
			yes = true;

		if (!yes) {
			cur -= dice;
			next = one[0];
			if (cur >= 0 && board[cur] >= 3)
				yes = true;
		}
	}
	else if (one.size() == 2) {
		cur = one[0];
		next = cur + dice;
		if (next == one[1])
			yes = true;
	}
	else
		yes = false;

	if (yes)
		cout << "YES\n" << cur << ' ' << next;
	else
		cout << "NO";
}