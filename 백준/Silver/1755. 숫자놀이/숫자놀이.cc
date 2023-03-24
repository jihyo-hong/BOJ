// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> mp;

string arr[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
vector<pair<string, int>> v;

bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        string s = "";
        string num = to_string(i);
        for (int j = 0; j < num.size(); j++) {
            s += (arr[num[j] - '0'] + ' ');
        }
        v.push_back({ s, i });
    }
    
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n - m + 1; i++) {
        cout << v[i].second << ' ';
        if ((i + 1) % 10 == 0)
            cout << '\n';
    }
    return 0;
}