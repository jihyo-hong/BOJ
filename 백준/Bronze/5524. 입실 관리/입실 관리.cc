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
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++)
			if ('A' <= s[i] && s[i] <= 'Z')
				s[i] += 32;
		cout << s << '\n';
	}
}

void solve() {
	
}