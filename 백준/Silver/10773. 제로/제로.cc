#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> s;
	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		if (n) {
			s.push(n);
		}
		else {
			s.pop();
		}
	}
	int size = s.size();
	int sum = 0;
	while (size--) {
		sum += s.top();
		s.pop();
	}
	cout << sum;

	return 0;
}