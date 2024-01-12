#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str{};
	getline(cin, str);
	while (str != ".") {
		bool wellBalanced = true;
		deque<char> dq;
		for (char c : str) {
			if (c == '(' || c == '[') dq.push_back(c);
			else if (c == ')') {
				if (dq.empty()) wellBalanced = false;
				else if (dq.back() != '(') wellBalanced = false;
				else dq.pop_back();
				if (!wellBalanced) break;
			}
			else if (c == ']') {
				if (dq.empty()) wellBalanced = false;
				else if (dq.back() != '[') wellBalanced = false;
				else dq.pop_back();
				if (!wellBalanced) break;
			}
		}
		if (dq.size()) wellBalanced = false;
		if (wellBalanced) cout << "yes\n";
		else cout << "no\n";
		getline(cin, str);
	}

	return 0;
}