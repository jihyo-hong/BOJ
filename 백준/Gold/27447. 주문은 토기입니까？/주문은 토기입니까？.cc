#include <iostream>
#include <map>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

void input();
void solve();

int n, m;
int t = 0;
int pottery = 0;
vector<int> people;
int coffee = 0;
string ans = "success";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		people.push_back(p);
	}
}

void solve() {
	int s = 0;
	int i = 0;
	int p = 0;;
	while (s < n) {
		if (i < n)
			p = people[i];
		if (t == people[s]) {
			if (!coffee) {
				ans = "fail";
				break;
			}
			s++;
			coffee--;
		}
		else if (p - m <= t && coffee < i + 1 && pottery) {
			coffee++;
			pottery--;
			i++;
		}
		else
			pottery++;
		t++;
	}
	cout << ans;
}