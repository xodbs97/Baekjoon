#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	queue<char> str;
	queue<char> num;
	for (char c : s) {
		// 문자
		if (c >= 'A' && c <= 'Z') {
			str.push(c);
			if (num.size()) {
				while (num.size()) {
					cout << num.front();
					num.pop();
				}
				cout << "\n";
			}
		}
		// 숫자
		else if (c >= '0' && c <= '9') num.push(c);
		// 더하기
		else if (c == '+') {
			while (str.size()) {
				cout << str.front();
				str.pop();
			}
			cout << " tighten ";
		}
		// 빼기
		else if (c == '-') {
			while (str.size()) {
				cout << str.front();
				str.pop();
			}
			cout << " loosen ";
		}
	}
	while (num.size()) {
		cout << num.front();
		num.pop();
	}

	return 0;
}