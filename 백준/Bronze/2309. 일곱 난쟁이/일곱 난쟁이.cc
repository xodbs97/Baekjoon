#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	int sum = 0;
	int r = 9;
	while (r--) {
		int i;
		cin >> i;
		v.push_back(i);
		sum += i;
	}

	int i = 0, j = 0;
	bool b = false;
	for (; i < 8; i++) {
		int tmp = sum - v[i];
		for (j = i + 1; j < 9; j++) {
			if (tmp - v[j] == 100) {
				v[i] = 0;
				v[j] = 0;
				b = true;
				break;
			}
		}
		if (b) {
			break;
		}
	}
	sort(v.begin(), v.end());
	for (i = 2; i < 9; i++) {
		cout << v[i] << '\n';
	}

	return 0;
}