#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(void) {
	stack<int> s;
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		string cmd;
		getline(cin, cmd);
		if (cmd.find(" ") != string::npos) {
			int num = stoi(cmd.substr(cmd.find(" ")));
			s.push(num);
			continue;
		}
		int size = s.size();
		if (cmd == "pop") {
			cout << (size == 0 ? -1 : s.top()) << "\n";
			if (size != 0) {
				s.pop();
			}
		}
		else if (cmd == "size") {
			cout << size << "\n";
		}
		else if (cmd == "empty") {
			cout << (size == 0 ? 1 : 0) << "\n";
		}
		else if (cmd == "top") {
			cout << (size == 0 ? -1 : s.top()) << "\n";

		}
	}

	return 0;
}