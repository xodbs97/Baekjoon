#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int>v;
	int r = 5;
	int sum = 0;
	while (r--) {
		int i;
		cin >> i;
		v.push_back(i);
		sum += i;
	}
	sort(v.begin(), v.end());
	cout << sum / 5 << '\n' << v[2];

	return 0;
}