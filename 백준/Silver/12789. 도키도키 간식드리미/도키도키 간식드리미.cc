#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	queue<int> q;
	vector<int> v(n + 1);
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		q.push(num);
	}

	stack<int> s;

	int chk = 1;
	while (!q.empty()) {
		if (q.front() == chk) {
			q.pop();
			++chk;
			continue;
		}
		if (!s.empty() && s.top() == chk) {
			s.pop();
			++chk;
			continue;
		}

		if (s.empty()) {
			s.push(q.front());
			q.pop();
		}
		else {
			if (s.top() < q.front()) {
				cout << "Sad";
				return 0;
			}
			else {
				s.push(q.front());
				q.pop();
			}
		}
	}
	cout << "Nice";

	return 0;
}