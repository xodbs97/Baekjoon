#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;

	int n;
	cin >> n;
	while (n--) {
		int i;
		cin >> i;
		v.push_back(i);
	}
	sort(v.begin(), v.end());

	int x;
	cin >> x;
	int idx = 0;
	for (auto i : v) {
		if (i > x) {
			break;
		}
		++idx;
	}

	int ans = 0;
	for (int i = 0; i < idx; i++) {
		for (int j = i + 1; j < idx; j++) {
			if (v[i] + v[j] == x) {
				++ans;
			}
			else if (v[i] + v[j] > x) {
				break;
			}
		}
	}

	cout << ans;

	return 0;
}