#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<long long int, int> mp;
vector<long long int> v;

int test(long long int x, int n) {
	for (int i = 1; i <= n; i++)
		x = (x & 1 ? (2 * x) ^ 6 : (x / 2) ^ 6);
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long int n, x;
	cin >> x >> n;
	//cout << test(x, n) << endl;
	while (n--) {
		//cout << x << endl;
		mp.insert({ x, 0 });
		mp[x] += 1;
		if (mp[x] == 2)
			break;
		x = (x & 1 ? (2 * x) ^ 6 : (x / 2) ^ 6);
	}
	
	n++;
	v.push_back(x);
	while (n--) {
		//cout << x << endl;
		x = (x & 1 ? (2 * x) ^ 6 : (x / 2) ^ 6);
		if (v[0] == x) {
			n--;
			break;
		}
		v.push_back(x);
	}

	n++;
	int cycle = v.size();
	cout << (n ? v[n % cycle] : x);
}