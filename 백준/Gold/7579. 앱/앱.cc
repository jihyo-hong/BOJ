#include <iostream>
#include <algorithm>

using namespace std;

void input();
void solve();

pair<int, int> app[101];
int dp[10001];

int n, m;
int cost = 0;

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
	for (int i = 1; i <= n; i++)
		cin >> app[i].first;
	for (int i = 1; i <= n; i++) {
		cin >> app[i].second;
		cost += app[i].second;
	}
}

/*
* 메모리를 배열의 인덱스로 이용하는 것은 너무 비효율적(천만...?!)
* 그렇다면 남은 것은 비용
* dp[i] = i만큼의 비용이 들 때 메모리
* 
* 각각의 앱에 대해 비활성화가 가능한 상황에서 점화식 실행
* 
* ? 2차원 배열은 이전의 dp 값을 가져올 때 인덱스를 독립적으로 접근하니까 문제가 없음
* ? 하지만 1차원 배열은 dp가 딱 비용과만 관련되어 있으니까 인덱스를 이용한 중복처리가 불가능함
* ? = 얘를 비활성화했는지 안 했는지 알 수가 없다
* ? 그래서 for 문의 순서를 바꾸어서 처리해 주어야 함!
*/
void solve() {
	for (int i = 1; i <= n; i++)
		for (int j = cost; j >= app[i].second; j--)
			dp[j] = max(dp[j], dp[j - app[i].second] + app[i].first);

	//for (int i = 0; i <= cost; i++)
	//	cout << i << ' ' << dp[i] << endl;

	cout << lower_bound(dp, dp + cost + 1, m) - dp;
}