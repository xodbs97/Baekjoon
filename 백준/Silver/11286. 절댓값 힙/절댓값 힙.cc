#include <bits/stdc++.h>

using namespace std;

struct Compare {
	bool operator()(const int i, const int j) {
		if (i == j) return false;
		int ip = (i < 0 ? i * -1 : i);
		int jp = (j < 0 ? j * -1 : j);
		if (ip > jp) return true;
		if (ip < jp) return false;
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
	while (n--) {
		int i;
		cin >> i;
		if (i) pq.push(i);
		else {
			if (pq.size()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else cout << "0\n";
		}
	}

	return 0;
}