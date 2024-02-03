#include <bits/stdc++.h>

using namespace std;

struct Compare {
	bool operator()(const int i, const int j) {
		if (i == j) return false;
		if (i > j) return true;
		return false;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int, vector<int>, Compare>  pq;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int j;
		cin >> j;
		pq.push(j);
	}

	int ans = 0;
	while (pq.size() > 1) {
		ans += pq.top();
		int new_card = pq.top();
		pq.pop();
		ans += pq.top();
		new_card += pq.top();
		pq.pop();
		pq.push(new_card);
	}
	cout << ans;

	return 0;
}