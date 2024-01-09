#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;

	int n;
	cin >> n;
	cin.ignore();

	while (n--) {
		string cmd;
		getline(cin, cmd);

		if (cmd.find(" ") != string::npos) {
			q.push(stoi(cmd.substr(cmd.find(" ") + 1)));
		}
		else if (cmd.front() == 'p') {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (cmd.front() == 's') {
			cout << q.size() << '\n';
		}
		else if (cmd.front() == 'e') {
			cout << (q.empty() ? 1 : 0) << '\n';
		}
		else if (cmd.front() == 'f') {
			cout << (q.empty() ? -1 : q.front()) << '\n';
		}
		else if (cmd.front() == 'b') {
			cout << (q.empty() ? -1 : q.back()) << '\n';
		}
	}

	return 0;
}