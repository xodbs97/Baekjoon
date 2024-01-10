#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string cmd;
		cin >> cmd;
		int n;
		cin >> n;
		string list;
		cin >> list;
		stringstream ss(list);
		deque<int> dq;
		char discard;
		int num;
		ss >> discard;
		while (ss >> num) {
			dq.push_back(num);
			ss >> discard;
		}
        
		bool right = true;
		bool is_success = true;
		for (char c : cmd) {
			if (c == 'R') right = !right;
			else {
				if (dq.empty()) {
					cout << "error\n";
					is_success = false;
					break;
				}
				if (right) dq.pop_front();
				else dq.pop_back();
			}
		}
		if (is_success) {
			cout << '[';
			int size = dq.size();
			if (right) {
				for (int i = 0; i < size; i++) {
					cout << dq.front();
					dq.pop_front();
					if (i != size - 1) cout << ',';
				}
			}
			else {
				for (int i = 0; i < size; i++) {
					cout << dq.back();
					dq.pop_back();
					if (i != size - 1) cout << ',';
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}