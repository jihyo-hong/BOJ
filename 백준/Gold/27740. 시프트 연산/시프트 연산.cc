#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

void input();
void solve();
void calc(int, int, int);

int n;
vector<int> num;
int zero[300000];
int memo[3];
int ans = 300000;

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
	int cnt = 0;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
		if (cnt) {
			if (tmp == 0)
				cnt++;
			else {
				zero[idx] = cnt;
				cnt = 0;
			}
		}
		else {
			if (tmp == 0) {
				idx = i;
				cnt++;
			}
		}
	}

}

/*
* 답의 형태는 두 가지임
* 1. 한쪽으로 시프트(LLL... 또는 RRR...)
* 2. 한쪽으로 시프트 했다가 다른 쪽으로 시프트(LL...RRR... 또는 RR...LLL...)
* 
* 1번보다 2번이 유리한 건 0이 연속으로 이어지는 구간이 존재하는 경우
* ex) 0 1 0 0 0 0 1 1 1 1
* 이 경우 해당 수열을 세 부분으로 나눌 수 있는데 (왼쪽 + 0 + 오른쪽)임
* 
* 위 수열을
* 1번으로 풀 때의 연산 개수 = 왼쪽 + 0 + 오른쪽
* 2번으로 풀 때의 연산 개수 = 왼쪽 + 왼쪽 + 오른쪽
* 
* 여기서 중복되는 부분을 제외하면 1번의 0, 2번의 왼쪽이 남는데
* 2번이 유리해지려면 결국 왼쪽 < 0이 되어야 한다는 걸 뜻함
* 즉, 0이 연속된 구간을 기준으로 양쪽에 있는 수들의 개수가 적으면 2번이 정답
* 물론 예외가 존재하기에 두 방법 모두 돌려서 체크
* 
* zero[i] = i 위치부터 이어지는 0의 개수
* memo[0] = (0: 왼쪽 먼저, 1: 오른쪽 먼저)
* memo[1-2] = 왼쪽-오른쪽 시프트 횟수
* 
*/
void solve() {
	// 한쪽으로 미는 경우
	// 양쪽에서 가장 먼저 나오는 1의 위치에 따라 시프트 횟수가 결정됨
	int l = n;
	int r = n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (num[i]) {
			l = i;
			break;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (num[i]) {
			r = n - i - 1;
			break;
		}
	}

	if (l == r) { // 1의 위치가 대칭인 경우
		cnt = n - l;
		calc(cnt, cnt, 0);
	}
	else {
		if (l < r) {
			cnt = n - r;
			calc(cnt, cnt, 0);
		}
		else {
			cnt = n - l;
			calc(cnt, 0, cnt);
		}
	}

	// 한쪽으로 밀었다가 다시 미는 경우
	// 배열에 저장된 0의 개수와 인덱스를 이용해 왼쪽과 오른쪽 개수를 판단
	for (int i = 0; i < n; i++) {
		int z = zero[i];
		if (z) {
			l = i;
			r = n - i - z;
			if (l < z) {
				cnt = (l * 2) + r;
				calc(cnt, l, l + r);
			}
			if (r < z) {
				cnt = l + (r * 2);
				calc(cnt, l + r, r);
			}
		}

	}

	string s = "";
	if (memo[0] == 0) {
		for (int i = 0; i < memo[1]; i++)
			s += 'L';
		for (int i = 0; i < memo[2]; i++)
			s += 'R';
	}

	else {
		for (int i = 0; i < memo[2]; i++)
			s += 'R';
		for (int i = 0; i < memo[1]; i++)
			s += 'L';
	}

	cout << ans << '\n' << s;
}

// 갱신용 함수
void calc(int cnt, int l, int r) {
	if (cnt < ans) {
		memo[0] = l < r ? 0 : 1;
		memo[1] = l;
		memo[2] = r;
		ans = cnt;
	}
}