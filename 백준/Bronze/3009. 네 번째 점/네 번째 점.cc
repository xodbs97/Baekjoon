#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	stack<int> xs, ys;
	for (int i = 0; i < 3; ++i) {
		int x, y;
		cin >> x >> y;

		if (xs.size()) {
			if (xs.top() == x) xs.pop();
			else xs.push(x);
		}
		else xs.push(x);

		if (ys.size()) {
			if (ys.top() == y) ys.pop();
			else ys.push(y);
		}
		else ys.push(y);
	}
	if (xs.size() == 3) xs.pop();
	if (ys.size() == 3) ys.pop();
	cout << xs.top() << " " << ys.top();

	return 0;
}