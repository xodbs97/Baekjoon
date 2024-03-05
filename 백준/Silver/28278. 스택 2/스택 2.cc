#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> s;
	int n;
	cin >> n;
	while (n--) {
		int inst;
		cin >> inst;
		if (inst == 1) {
			int num;
			cin >> num;
			s.push(num);
			continue;
		}
		else if (inst == 2) {
			if (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			else cout << -1;
		}
		else if (inst == 3) cout << s.size();
		else if (inst == 4) {
			if (s.empty()) cout << 1 ;
			else cout << 0 ;
		}
		else if (inst == 5) {
			if (!s.empty()) cout << s.top();
			else cout << -1;
		}
		cout << "\n";
	}

	return 0;
}