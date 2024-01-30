#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<int, string> umi; // 도감 번호, 포켓몬 이름
	unordered_map<string, int> ums; // 포켓몬 이름, 도감 번호

	int n, m; // 포켓몬의 개수, 문제의 개수
	cin >> n >> m;
	for (int idx = 1; idx <= n; idx++) {
		string name;
		cin >> name;
		umi[idx] = name;
		ums[name] = idx;
	}
	while (m--) {
		string str;
		cin >> str;
		if (str[0] >= '0' && str[0] <= '9') { // 숫자인지 문자인지 체크
			int num = stoi(str);
			cout << umi.at(num) << "\n";
		}
		else cout << ums.at(str) << "\n";
	}
	return 0;
}