#include <bits/stdc++.h>

using namespace std;

vector<int> v(10001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		int i;
		cin >> i;
		++v[i];
	}

	for (int i = 1; i <= 10000; ++i) {
		if (v[i]) {
			while (v[i]--) cout << i << "\n";
		}
	}

	return 0;
}