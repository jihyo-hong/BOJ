#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

void solve();
void solve2();
bool solve3();

string s, bomb;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> bomb;
	//while (solve3());

	solve();

	return 0;
}

/*
* solve2()를 보완
* 문자열을 잘랐다 이어붙이는 것은 시간이 많이 듬 -> 이 부분을 스택으로 처리
* 문자열 스택에서 하나씩 빼면서 또다른 스택에 넣음
* 뺀 문자가 폭발 문자열의 일부이다? -> flag와 connected를 적절히 갱신하면서 처리
* (뒤에서부터 비교)
* 모르겠당 일단 제출
* 아 졸려
* 
* 위 코드의 문제점: 문자가 달라서 다음으로 넘어갔는데, 그 문자가 폭발해야 하는 경우
* babbb
* babb
* -> 시작부터 하나하나 비교하지 말고 끝을 비교하자!
* 끝 부분의 원소를 훑어야 하므로 stack이 아닌 vector 사용
* 
*/
void solve() {
	int bl = bomb.length();
	vector<char> stack;
	for (int i = 0; i < s.length(); i++) {
		int c = s[i];
		stack.push_back(c);
		if (c == bomb[bl - 1] && stack.size() >= bl) {
			int isexploding = true;
			int si = stack.size() - bl;
			int bi = 0;
			for (; bi < bl; si++, bi++) {
				if (stack[si] != bomb[bi]) {
					isexploding = false;
					break;
				}
			}
			if (isexploding) {
				stack.erase(stack.begin() + stack.size() - bl, stack.begin() + stack.size());
			}
		}
	}
	if (stack.empty())
		cout << "FRULA";
	else
		for (int i = 0; i < stack.size(); i++)
			cout << stack[i];
}

/*
* 스택 안 쓰고 구현하다가 실패
*/
void solve2() {
	int b = bomb.length();
	int flag = 0;
	bool connected = false;
	for (int i = 0; i < s.length(); i++) {
		if (!connected && s[i] == bomb[flag]) {
			flag++;
			connected = true;
		}

		else if (connected && s[i] == bomb[flag]) {
			flag++;
			if (flag == b) {
				i -= (b - 1);
				s = s.substr(0, i) + s.substr(i + b, s.length() - i - b);
				i = (i - (b + 1) <= 0 ? -1 : i - (b + 1));
				flag = 0;
				connected = false;
			}
		}

		else {
			connected = false;
			i -= flag;
			flag = 0;
		}
	}
}

/*
* 그냥 냅다 구현
*/
bool solve3() {
	int idx = s.find(bomb);
	if (idx == string::npos)
		return false;
	s = s.substr(0, idx) + s.substr(idx + bomb.length(), s.length() - idx - bomb.length());
	return true;
}
